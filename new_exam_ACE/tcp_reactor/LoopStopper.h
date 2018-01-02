#include "ace/Reactor.h"
#include "ace/Log_Msg.h"

class LoopStopper : public ACE_Event_Handler
{
        public:
                LoopStopper (int signum = SIGINT);

                // Called when object is signaled by OS.

                virtual int handle_signal (int signum,
                                siginfo_t * = 0,
                                ucontext_t * = 0);
};


LoopStopper::LoopStopper (int signum)
{
        ACE_Reactor::instance ()->register_handler (signum, this);
}

       
int LoopStopper::handle_signal (int, siginfo_t *, ucontext_t *)
{
        ACE_Reactor::instance ()->end_reactor_event_loop ();
        return 0;
}

