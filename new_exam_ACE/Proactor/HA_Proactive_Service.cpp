#include "HA_Proactive_Service.h"
#include "ace/OS.h"
#include "ace/Log_Msg.h"
#include "ace/Message_Block.h"


HA_Proactive_Service::~HA_Proactive_Service ()
{
        if (this->handle () != ACE_INVALID_HANDLE)
                ACE_OS::closesocket (this->handle ());
}


void HA_Proactive_Service::open (ACE_HANDLE h, ACE_Message_Block&)
{
        this->handle (h);  //socket handle
        if (this->reader_.open (*this) != 0 ||
                        this->writer_.open (*this) != 0   )
        {
                ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("HA_Proactive_Service open")));
                delete this;
                return;
        }

        ACE_Message_Block *mb;
        ACE_NEW_NORETURN (mb, ACE_Message_Block (1024*1024));
        if (this->reader_.read (*mb, mb->space ()) != 0)
        {
                ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                                        ACE_TEXT ("HA_Proactive_Service begin read")));
                mb->release ();
                delete this;
                return;
        }

        ACE_DEBUG((LM_DEBUG,ACE_TEXT("HA_Proactive_Service::open end\n")));
        // mb is now controlled by Proactor framework.
        return;
}


void HA_Proactive_Service::handle_read_stream(const ACE_Asynch_Read_Stream::Result &result)
{
        ACE_Message_Block &mb = result.message_block ();
        if (!result.success () || result.bytes_transferred () == 0)
        {
                mb.release ();
                delete this;
        }
        else
        {
                ACE_DEBUG((LM_DEBUG,ACE_TEXT("%d and mb length %d\n"), result.bytes_transferred (), mb.length()));
                // ACE_DEBUG((LM_DEBUG,ACE_TEXT("%s\n"), mb.rd_ptr()));
                // mb.wr_ptr(mb.base());
                // ACE_DEBUG((LM_DEBUG,ACE_TEXT("mb length %d and space %d\n"),  mb.length(),mb.space()));
                // mb.wr_ptr(1024*194);
                // ACE_DEBUG((LM_DEBUG,ACE_TEXT("mb length %d and space %d\n"),  mb.length(),mb.space()));
                if (this->writer_.write (mb, mb.length()+1024) != 0)
                {
                        ACE_ERROR ((LM_ERROR,
                                                ACE_TEXT ("%p\n"),
                                                ACE_TEXT ("starting write")));
                        mb.release ();
                }
                else
                {
                        ACE_Message_Block *new_mb;
                        ACE_NEW_NORETURN (new_mb, ACE_Message_Block (1024*1024));
                        this->reader_.read (*new_mb, new_mb->space ());
                }
        }
        return;
}


void HA_Proactive_Service::handle_write_stream(const ACE_Asynch_Write_Stream::Result &result)
{
        // ACE_Message_Block &mb = result.message_block ();
        // ACE_DEBUG((LM_DEBUG,ACE_TEXT("handle_write_stream : %d and mb length %d\n"), result.bytes_transferred (), mb.length()));
        result.message_block ().release ();
        return;
}

