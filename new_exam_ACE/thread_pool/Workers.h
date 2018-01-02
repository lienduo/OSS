#include "ace/Task.h"
#include "ace/Log_Msg.h"


class Workers : public ACE_Task<ACE_MT_SYNCH>
{
        public:
                Workers ()
                { }

                virtual int svc (void)
                {
                        while (1)
                        {
                                ACE_Message_Block *mb = NULL;
                                if (this->getq (mb) == -1)
                                {
                                        ACE_DEBUG ((LM_INFO,
                                                                ACE_TEXT ("(%t) Shutting down\n")));
                                        break;
                                }

                                // Process the message.
                                process_message (mb);
                        }

                        return 0;
                }

                int process_message(ACE_Message_Block* mb)
                {
                        return 0;
                }
};
