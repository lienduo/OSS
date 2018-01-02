#include "ace/Proactor.h"
#include "ace/Log_Msg.h"
#include "HA_Proactive_Acceptor.h"

int ACE_TMAIN (int, ACE_TCHAR *[])
{
        ACE_INET_Addr listen_addr(50000);     // Set up with listen port
        HA_Proactive_Acceptor aio_acceptor;
        if (0 != aio_acceptor.open (listen_addr,
                                0,     // bytes_to_read
                                0,     // pass_addresses
                                ACE_DEFAULT_BACKLOG,
                                1,     // reuse_addr
                                0,     // proactor
                                1))    // validate_new_connection
                ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("acceptor open")), 1);

        ACE_Proactor::instance ()->proactor_run_event_loop ();
        return 0;
}

/*
   ACE_INET_Addr peer_addr;    // Set up peer addr
   ACE_Asynch_Connector<HA_Proactive_Service> aio_connect;
   aio_connect.connect (peer_addr);
 */

