/*  TIMER_MILLIS.H ***************************************************
**  Library for Ardunio timer functions based on the Millis counter
**
**  Library created by Peter Gossler
**  Latest released version 0.1
**  Release date: 21/04/2017
**********************************************************************/

#ifndef TIMER_MILLIS
    #define TIMER_MILLIS
    #define TMR_DEFAULT_TO 10

    class TimerMillis {
        public:
            TimerMillis (unsigned long to);
            bool IsElapsed ();
            void Reset ();
            void Start ();
            void Stop ();
            void Set (unsigned long to);
            unsigned long Get ();
            unsigned long GetTimeout();
            unsigned long GetDelta();
            unsigned long GetLastMillis ();
            #ifdef DEBUG
                unsigned long GetDebugCounter ();
            #endif
            //void TimerSetCallBack ()
        private:
            unsigned long   _timeout;
            unsigned long   _last_millis;
            unsigned long   _dif;
            #ifdef DEBUG
                unsigned long   _debug_counter;
            #endif
            bool            _timer_active;
    };
#endif // #ifdef TIMER_MILLIS

