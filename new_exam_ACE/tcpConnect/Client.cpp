#include "Client.h"
#include <iostream>

int Client::open (void *p)
{
        ACE_Time_Value iter_delay (2);   // Two seconds
        if (super::open (p) == -1)
                return -1;
  
        this->iterations_ = 0;
        // this->notifier_.reactor (this->reactor ());
        // this->msg_queue ()->notification_strategy (&this->notifier_);
        this->reactor ()->register_handler
                (this, ACE_Event_Handler::WRITE_MASK|ACE_Event_Handler::READ_MASK);

        return this->reactor()->schedule_timer
                (this, 0, ACE_Time_Value::zero, iter_delay);
}

int Client::handle_input (ACE_HANDLE)
{
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("client recv data\n")));
        char buf[64];
        ssize_t recv_cnt = this->peer ().recv (buf, sizeof (buf) - 1);
        if (recv_cnt > 0)
        {
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%*C"),
                                        ACE_static_cast (int, recv_cnt),
                                        buf));
                return 0;
        }
        if (recv_cnt == 0 || ACE_OS::last_error () != EWOULDBLOCK)
        {
                perror("recv : ");
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("client recv %d data\n"),recv_cnt));
                this->reactor ()->end_reactor_event_loop ();
                return -1;
        }
        return 0;
}

int Client::handle_timeout(const ACE_Time_Value &, const void *)
{
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("client timeout\n")));
        if (this->iterations_ >= ITERATIONS)
        {
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("client close_writer\n")));
                this->peer ().close_writer ();
                return 0;
        }

        ACE_Message_Block *mb;
        char msg[64];
        ACE_OS::sprintf (msg, "Iteration %d\0", this->iterations_);
        ACE_NEW_RETURN (mb, ACE_Message_Block (strlen(msg)+1), -1);
        mb->copy(msg,strlen(msg)+1);
        std::cout<<mb->rd_ptr()<<" before putq  "<<mb->length()<<std::endl;
        this->putq (mb); 
 
        this->iterations_++;
        this->reactor ()->register_handler
                (this, ACE_Event_Handler::WRITE_MASK);

        return 0;
}

int Client::handle_output (ACE_HANDLE)
{
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("client send data\n")));
        ACE_Message_Block *mb;
        ACE_Time_Value nowait (ACE_OS::gettimeofday ());
        while (-1 != this->getq (mb, &nowait))
        {
                std::cout<<(char*)mb->rd_ptr()<<"   "<<mb->length()<<std::endl;
                ssize_t send_cnt =
                        this->peer().send (mb->rd_ptr(), mb->length());
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("client send %d data ok\n"), send_cnt));
                if (send_cnt == -1)
                        ACE_ERROR ((LM_ERROR,
                                                ACE_TEXT ("(%P|%t) %p\n"),
                                                ACE_TEXT ("send")));
                else
                        mb->rd_ptr (ACE_static_cast (size_t, send_cnt));
                std::cout<<mb->length()<<std::endl;
                if (mb->length () > 0)
                {
                        this->ungetq (mb);
                        break;
                }
                std::cout<<mb->size()<<std::endl;
                mb->release ();
        }
        if (this->msg_queue ()->is_empty ())
                this->reactor ()->cancel_wakeup
                        (this, ACE_Event_Handler::WRITE_MASK);
        else
                this->reactor ()->schedule_wakeup
                        (this, ACE_Event_Handler::WRITE_MASK);
        return 0;
}

