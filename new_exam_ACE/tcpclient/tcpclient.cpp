#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Connector.h"
#include "ace/Log_Msg.h"

int ACE_TMAIN (int, ACE_TCHAR *[])
{
        // ACE_INET_Addr srvr (50000, ACE_LOCALHOST);
        ACE_INET_Addr srvr(50000,"10.0.0.4");
        // ACE_INET_Addr srvr(49049,"3ffe:0:101::82");//, PF_INET6);
        // 这里的addr是所有连接的ip和端口，客户端使用的端口，有系统自定！

        ACE_SOCK_Connector connector;
        ACE_SOCK_Stream peer;

        if (-1 == connector.connect (peer, srvr))

                ACE_ERROR_RETURN ((LM_ERROR,
                                        ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("connect")), 1);

        ACE_DEBUG((LM_DEBUG,ACE_TEXT("connect ok!\n")));
        
        int bc;
        char buf[64];

        peer.send_n ("uptime\n", 7);
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("Send ok!\n")));
        
        bc = peer.recv (buf, sizeof(buf));
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("Receive ok!\n")));
 
        sleep(2);
        write (1, buf, bc);
        peer.close ();

        return (0);
}
