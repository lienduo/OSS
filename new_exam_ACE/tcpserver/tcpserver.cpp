/*As the server is written, it will process only one request on one client 
  connection and then exit. If we wrap a simple while loop around everything
  following the accept(), we can service multiple clients 
  but only one at a time*/



#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Log_Msg.h"

int ACE_TMAIN (int, ACE_TCHAR *[])
{
        // ACE_INET_Addr port_to_listen ("HAStatus");
        // ACE_INET_Addr port_to_listen (50000);
        ACE_INET_Addr port_to_listen ("50000","10.0.0.4");
        ACE_SOCK_Acceptor acceptor;

        if (acceptor.open (port_to_listen, 1) == -1)
                ACE_ERROR_RETURN ((LM_ERROR,
                                        ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("acceptor.open")),
                                100);

        /*
         * The complete open signature:
         *
         int open (const ACE_Addr &local_sap,
         int reuse_addr = 0,
         int protocol_family = PF_INET,
         int backlog = ACE_DEFAULT_BACKLOG,
         int protocol = 0);
         *
         */

        while (1)
        {
                ACE_SOCK_Stream peer;
                ACE_INET_Addr peer_addr;
                ACE_Time_Value timeout (10, 0);

                /*
                 * Basic acceptor usage
                 */
#if 0
                if (acceptor.accept (peer) == -1)
                        ACE_ERROR_RETURN ((LM_ERROR,
                                                ACE_TEXT ("(%P|%t) Failed to accept ")
                                                ACE_TEXT ("client connection\n")),
                                        100);
#endif /* 0 */

                ACE_DEBUG((LM_DEBUG,ACE_TEXT("wait for conection\n")));

                if (acceptor.accept (peer, &peer_addr, &timeout, 0) == -1)
                {
                        if (ACE_OS::last_error() == EINTR)
                                ACE_DEBUG ((LM_DEBUG,
                                                        ACE_TEXT ("(%P|%t) Interrupted while ")
                                                        ACE_TEXT ("waiting for connection\n")));
                        else
                                if (ACE_OS::last_error() == ETIMEDOUT)
                                        ACE_DEBUG ((LM_DEBUG,
                                                                ACE_TEXT ("(%P|%t) Timeout while ")
                                                                ACE_TEXT ("waiting for connection\n")));
                }
                else
                {
                        ACE_TCHAR peer_name[MAXHOSTNAMELEN];
                        peer_addr.addr_to_string (peer_name, MAXHOSTNAMELEN);
                        ACE_DEBUG ((LM_DEBUG,
                                                ACE_TEXT ("(%P|%t) Connection from %s\n"),
                                                peer_name));
                        char buffer[4096];
                        ssize_t bytes_received;

                        // while ((bytes_received =
                        //                         peer.recv (buffer, sizeof(buffer))) != -1)
                        // {
                        //         peer.send_n (buffer, bytes_received);
                        // }
                        //
                        while((bytes_received =
                                                peer.recv (buffer, sizeof(buffer))) > 0)
                        {
                                peer.send_n (buffer, bytes_received);
                        }
                        peer.close ();
                }
        }

        return (0);
}
