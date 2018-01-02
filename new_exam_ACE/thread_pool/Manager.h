#include "Workers.h"
#include "ace/OS.h"

class Manager : public ACE_Task<ACE_MT_SYNCH>
{
        public:
                enum {POOL_SIZE = 5, MAX_TIMEOUT = 5};

                Manager () : shutdown_(0)
                {
                        ACE_TRACE (ACE_TEXT ("Manager::Manager"));
                }

                int svc (void)
                {
                        ACE_TRACE (ACE_TEXT ("Manager::svc"));

                        ACE_DEBUG ((LM_INFO, ACE_TEXT ("(%t) Manager started\n")));

                        // Create pool.
                        Workers pool;
                        pool.activate (THR_NEW_LWP | THR_JOINABLE, POOL_SIZE);

                        while (!done ())
                        {
                                ACE_Message_Block *mb = NULL;
                                ACE_Time_Value tv ((long)MAX_TIMEOUT);
                                tv += ACE_OS::time (0);

                                // Get a message request.
                                if (this->getq (mb, &tv) < 0)
                                {
                                        pool.msg_queue ()->deactivate ();
                                        pool.wait ();
                                }

                                // Ask the worker pool to do the job.
                                pool.putq (mb);
                        }

                        return 0;
                }

        private:
                int done (void);

                int shutdown_;
};

