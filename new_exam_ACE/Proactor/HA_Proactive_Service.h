#include "ace/Asynch_IO.h"

class HA_Proactive_Service : public ACE_Service_Handler
{
        public:
                ~HA_Proactive_Service ();
 
                // called when a new connection is established.
                virtual void open (ACE_HANDLE h, ACE_Message_Block&);

                // This method will be called when an asynchronous read
                // completes on a stream.
                virtual void handle_read_stream
                        (const ACE_Asynch_Read_Stream::Result &result);

                // This method will be called when an asynchronous write
                // completes on a stream.
                virtual void handle_write_stream
                        (const ACE_Asynch_Write_Stream::Result &result);

        private:
                ACE_Asynch_Read_Stream reader_;
                ACE_Asynch_Write_Stream writer_;
};

