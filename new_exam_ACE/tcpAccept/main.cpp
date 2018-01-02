#include "ace/Log_Msg.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ClientService.h"
#include "LoopStopper.h"

typedef ACE_Acceptor<ClientService, ACE_SOCK_ACCEPTOR> ClientAcceptor;

int ACE_TMAIN (int, ACE_TCHAR *[])
{
        LoopStopper stopper;
        // ACE_INET_Addr port_to_listen ("HAStatus");
        ACE_INET_Addr port_to_listen (50000);
        ClientAcceptor acceptor;
        if (acceptor.open (port_to_listen) == -1)
                return 1;

        ACE_Reactor::instance ()->run_reactor_event_loop ();

        return (0);
}
