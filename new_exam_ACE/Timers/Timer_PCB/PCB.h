/* -*- C++ -*- */
// PCB.h,v 1.2 2004/01/03 22:31:20 shuston Exp

#if !defined(PCB_H)
#define PCB_H

// Listing 1 code/ch20
class PCB
{
        public:
                PCB ();

                // Set/get the timer id that is being handled by this instance.
                void setID (long timerID);
                long getID (void) const;

                // Handle a timeout event, cancel, and close.
                virtual int handleEvent (const void *arg);
                virtual int handleCancel (void);
                virtual int handleClose (void);

        private:
                long timerID_;
                int count_;
};
// Listing 1

#endif /*PCB_H*/
