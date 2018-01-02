#include "ace/Asynch_Acceptor.h"
#include "ace/INET_Addr.h"
#include "HA_Proactive_Service.h"

class HA_Proactive_Acceptor :
        public ACE_Asynch_Acceptor<HA_Proactive_Service>
{
        public:
                virtual int validate_connection
                        (const ACE_Asynch_Accept::Result& result,
                         const ACE_INET_Addr &remote,
                         const ACE_INET_Addr &local)
                        {

                                struct in_addr *remote_addr =
                                        ACE_reinterpret_cast (struct in_addr*,
                                                        remote.get_addr ());
                                struct in_addr *local_addr =
                                        ACE_reinterpret_cast (struct in_addr*,
                                                        local.get_addr ());
                                if (inet_netof (*local_addr) == inet_netof (*remote_addr))
                                        return 0;

                                return -1;
                        }

};



