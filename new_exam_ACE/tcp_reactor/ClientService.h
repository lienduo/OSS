#include "ace/Message_Block.h"
#include "ace/Message_Queue.h"
#include "ace/SOCK_Stream.h"
#include "ace/Synch.h"

class ClientService : public ACE_Event_Handler
{
        public:
                ACE_SOCK_Stream &peer (void) { return this->sock_; }

                int open (void);

                // Get this handler's I/O handle.
                virtual ACE_HANDLE get_handle (void) const
                { return this->sock_.get_handle (); }

                // Called when input is available from the client.
                virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);

                // Called when output is possible.
                virtual int handle_output (ACE_HANDLE fd = ACE_INVALID_HANDLE);

                // Called when this handler is removed from the ACE_Reactor.
                virtual int handle_close (ACE_HANDLE handle,
                                ACE_Reactor_Mask close_mask);

        protected:
                ACE_SOCK_Stream sock_;
                ACE_Message_Queue<ACE_NULL_SYNCH> output_queue_;
};

