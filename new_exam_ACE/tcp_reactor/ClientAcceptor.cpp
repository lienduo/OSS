#include "ClientAcceptor.h"
#include "ClientService.h"

ClientAcceptor::ClientAcceptor()
{}


ClientAcceptor::~ClientAcceptor ()
{
        this->handle_close (ACE_INVALID_HANDLE, 0);
}

int ClientAcceptor::open (const ACE_INET_Addr &listen_addr)
{
        if (this->acceptor_.open (listen_addr, 1) == -1)
                ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("acceptor.open")),
                                -1);
        return this->reactor ()->register_handler
                (this, ACE_Event_Handler::ACCEPT_MASK);
}


int ClientAcceptor::handle_input (ACE_HANDLE)
{
        ClientService *client;
        ACE_NEW_RETURN (client, ClientService, -1);

        auto_ptr<ClientService> p (client);

        if (this->acceptor_.accept (client->peer ()) == -1)
                ACE_ERROR_RETURN ((LM_ERROR,
                                        ACE_TEXT ("(%P|%t) %p\n"),
                                        ACE_TEXT ("Failed to accept ")
                                        ACE_TEXT ("client connection")),
                                -1);
        p.release ();
        client->reactor (this->reactor ());
        if (client->open () == -1)
                client->handle_close (ACE_INVALID_HANDLE, 0);
        return 0;
}


int ClientAcceptor::handle_close (ACE_HANDLE handler, ACE_Reactor_Mask mask)
{
        ACE_DEBUG((LM_DEBUG,ACE_TEXT("ACE_Reactor_Mask : %d\n"), mask));

        if (this->acceptor_.get_handle () != ACE_INVALID_HANDLE)
        {
                ACE_DEBUG((LM_DEBUG,ACE_TEXT("ClientAcceptor::handle_close\n")));

                ACE_Reactor_Mask m = ACE_Event_Handler::ACCEPT_MASK |
                        ACE_Event_Handler::DONT_CALL;
                this->reactor ()->remove_handler (this, m);
                this->acceptor_.close ();
        }
                
        return 0;
}


