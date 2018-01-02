#include "ace/Reactor.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Connector.h"
#include "ace/Connector.h"
#include "Client.h"


int ACE_TMAIN (int, ACE_TCHAR *[])
{
        // ACE_INET_Addr port_to_connect ("HAStatus", ACE_LOCALHOST);
        ACE_INET_Addr port_to_connect (50000, ACE_LOCALHOST);
        ACE_Connector<Client, ACE_SOCK_CONNECTOR> connector;
        Client client;
        Client *pc = &client;
        if (connector.connect (pc, port_to_connect) == -1)
                ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("connect")), 1);

        ACE_Reactor::instance ()->run_reactor_event_loop ();
        return (0);
}

