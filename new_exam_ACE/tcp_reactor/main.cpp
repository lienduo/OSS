#include "ClientAcceptor.h"
#include "ClientService.h"
#include "ace/OS.h"
#include "LoopStopper.h"

int ACE_TMAIN (int, ACE_TCHAR *[])
{
        // ACE_INET_Addr port_to_listen ("HAStatus");
        LoopStopper stopper;
        ACE_INET_Addr port_to_listen (50000);
        ClientAcceptor acceptor;
        acceptor.reactor (ACE_Reactor::instance ());
        if (acceptor.open (port_to_listen) == -1)
                return 1;
        
        ACE_Reactor::instance ()->run_reactor_event_loop ();
        
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("main close \n")));
        return (0);
}
