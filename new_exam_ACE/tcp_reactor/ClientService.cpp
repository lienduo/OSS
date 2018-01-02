#include "ClientService.h"
#include "ace/Reactor.h"

int ClientService::open (void)
{
        ACE_TCHAR peer_name[MAXHOSTNAMELEN];
        ACE_INET_Addr peer_addr;
        if (this->sock_.get_remote_addr (peer_addr) == 0 &&
                        peer_addr.addr_to_string (peer_name, MAXHOSTNAMELEN) == 0)
                ACE_DEBUG ((LM_DEBUG,
                                        ACE_TEXT ("(%P|%t) Connection from %s\n"),
                                        peer_name));
        return this->reactor()->register_handler
                (this, ACE_Event_Handler::READ_MASK);
}


int ClientService::handle_input (ACE_HANDLE)
{
        const size_t INPUT_SIZE = 4096;
        char buffer[INPUT_SIZE];
        ssize_t recv_cnt, send_cnt;

        /// if client close,a READ event will occor.so the input will be called,and recv() = 0 will occor!
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("Start recv \n")));
        if ((recv_cnt = this->sock_.recv (buffer, sizeof(buffer))) <= 0)
        {
                ACE_DEBUG ((LM_DEBUG,
                                        ACE_TEXT ("(%P|%t) Connection closed\n")));
                return -1;
        }
        sleep(20);
        send_cnt =
                this->sock_.send (buffer, ACE_static_cast (size_t, recv_cnt));
        
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("ClientService::handle_input end\n")));
        if (send_cnt == recv_cnt)
                return 0;
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
        ACE_NEW_RETURN
                (mb, ACE_Message_Block (&buffer[send_cnt], remaining), -1);
        int output_off = this->output_queue_.is_empty ();
        ACE_Time_Value nowait (ACE_OS::gettimeofday ());
        if (this->output_queue_.enqueue_tail (mb, &nowait) == -1)
        {
                ACE_ERROR ((LM_ERROR,
                                        ACE_TEXT ("(%P|%t) %p; discarding data\n"),
                                        ACE_TEXT ("enqueue failed")));
                mb->release ();
                return 0;
        }
        if (output_off)
                return this->reactor ()->register_handler
                        (this, ACE_Event_Handler::WRITE_MASK);
 
        return 0;
}

int ClientService::handle_output (ACE_HANDLE)
{
        ACE_Message_Block *mb;
        ACE_Time_Value nowait (ACE_OS::gettimeofday ());
        while (0 == this->output_queue_.dequeue_head
                        (mb, &nowait))
        {
                ssize_t send_cnt =
                        this->sock_.send (mb->rd_ptr (), mb->length ());
                if (send_cnt == -1)
                        ACE_ERROR ((LM_ERROR,
                                                ACE_TEXT ("(%P|%t) %p\n"),
                                                ACE_TEXT ("send")));
                else
                        mb->rd_ptr (ACE_static_cast (size_t, send_cnt));
                if (mb->length () > 0)
                {
                        this->output_queue_.enqueue_head (mb);
                        break;
                }
                mb->release ();
        }
        return (this->output_queue_.is_empty ()) ? -1 : 0;
}

        
int ClientService::handle_close (ACE_HANDLE, ACE_Reactor_Mask mask)
{
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("ClientService::handle_close Mask : %d \n"),mask));

        if (mask == ACE_Event_Handler::WRITE_MASK)
                return 0;
        mask = ACE_Event_Handler::ALL_EVENTS_MASK |
                ACE_Event_Handler::DONT_CALL;
        this->reactor ()->remove_handler (this, mask);
        this->sock_.close ();
        this->output_queue_.flush ();
        delete this;
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("ClientService::handle_close end \n")));
        return 0;
}


 
