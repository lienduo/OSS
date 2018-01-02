#include "ClientService.h"
#include "ace/Message_Block.h"

int ClientService::open (void *p)
{
        if (super::open (p) == -1)
                return -1;

        ACE_TCHAR peer_name[MAXHOSTNAMELEN];
        ACE_INET_Addr peer_addr;
        if (this->peer ().get_remote_addr (peer_addr) == 0 &&
                        peer_addr.addr_to_string (peer_name, MAXHOSTNAMELEN) == 0)
                ACE_DEBUG ((LM_DEBUG,
                                        ACE_TEXT ("(%P|%t) Connection from %s\n"),
                                        peer_name));
        return 0;
}

int ClientService::handle_input (ACE_HANDLE)
{
        const size_t INPUT_SIZE = 4096;
        char buffer[INPUT_SIZE];
        ssize_t recv_cnt, send_cnt;

        ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) wait for data\n")));
        recv_cnt = this->peer ().recv (buffer, sizeof(buffer));
        ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) recv data\n")));
        if (recv_cnt <= 0)
        {
                ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) Connection closed\n")));
                perror("recv");
                return -1;  //出错或者对方关闭，退出
        }

        send_cnt =
                this->peer ().send (buffer,
                                ACE_static_cast (size_t, recv_cnt));
        if (send_cnt == recv_cnt)
        {
                ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) send finish \n")));
                return 0;  //继续检测读事件,调用recv()会复位socket状态，使不可读 
                        //对方send，或者socket出错，均会使I/O可读
        }
        if (send_cnt == -1 && ACE_OS::last_error () != EWOULDBLOCK)
                ACE_ERROR_RETURN ((LM_ERROR,
                                        ACE_TEXT ("(%P|%t) %p\n"),
                                        ACE_TEXT ("send")),
                                0);
        if (send_cnt == -1)
                send_cnt = 0;
        ACE_Message_Block *mb;
        size_t remaining =
                ACE_static_cast (size_t, (recv_cnt - send_cnt));
        // ACE_NEW_RETURN
                // (mb, ACE_Message_Block (&buffer[send_cnt], remaining), -1);
        //mb的这种用法是错的，下面才是对的
        ACE_NEW_RETURN
                (mb, ACE_Message_Block ( remaining), -1);
        mb->copy( &buffer[send_cnt], remaining);

        int output_off = this->msg_queue ()->is_empty ();
        ACE_Time_Value nowait (ACE_OS::gettimeofday ());
        if (this->putq (mb, &nowait) == -1)
        {
                ACE_ERROR ((LM_ERROR,
                                        ACE_TEXT ("(%P|%t) %p; discarding data\n"),
                                        ACE_TEXT ("enqueue failed")));
                mb->release ();
                return 0;
        }
        if (output_off) //非空，触发handler_out回调
                return this->reactor ()->register_handler
                        (this, ACE_Event_Handler::WRITE_MASK);
        return 0;
}

int ClientService::handle_output (ACE_HANDLE)
{
        ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) wait for mb\n")));
        ACE_Message_Block *mb;
        ACE_Time_Value nowait (ACE_OS::gettimeofday ());
        while (-1 != this->getq (mb, &nowait))  //非阻塞
        {
                ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) get mb\n")));
                ssize_t send_cnt =
                        this->peer ().send (mb->rd_ptr (), mb->length ());
                if (send_cnt == -1)
                        ACE_ERROR ((LM_ERROR,
                                                ACE_TEXT ("(%P|%t) %p\n"),
                                                ACE_TEXT ("send")));
                else
                        mb->rd_ptr (ACE_static_cast (size_t, send_cnt));
                if (mb->length () > 0)
                {
                        this->ungetq (mb);
                        break;
                }
                mb->release ();
        }
        ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("(%P|%t) handle_output return\n")));
        return (this->msg_queue ()->is_empty ()) ? -1 : 0; 
        // selete属于水平检测，对于一个正常的socket，总是可写。如果此处返回0，那么handle_output将持续被回调！ 
        // 如果返回-1，则停止检测写事件，除非重新设置状态检测。
}

int ClientService::handle_close (ACE_HANDLE h, ACE_Reactor_Mask mask)
{
        if (mask == ACE_Event_Handler::WRITE_MASK)
                return 0;
        return super::handle_close (h, mask);
}



