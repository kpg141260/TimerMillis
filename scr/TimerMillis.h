/*  
**  TIMER_MILLIS.H **************************************************
**  Library for Ardunio timer functions based on the Millis counter
**
**  Library created by Peter Gossler
**  Latest released version 0.1
**  Release date: 21/04/2017
*********************************************************************
*/

#ifndef TIMER_MILLIS_H_
    #define TIMER_MILLIS_H_

    #define DEFAULT_TO  100
    #define ELAPSED     true
    #define NOT_ELAPSED false
    #define NOT_ACTIVE  false
    #define ACTIVE      true

    class TimerMillis {
        public:
            /** Function TimerMillis *****************************************************
            **
            **  Constructor for the TimerMillis class. Sets the timeout and starts timer.
            **
            **  Parameters: unsigned long timeout
            **              The timeout value for this instance. The value should be 
            **              greater than 0, if value is <= 0 the constructor will use the 
            **              default value TMR_DEFAULT_TO, which is 10 ms.
            **  Returns:    void - nothing
            *******************************************************************************/
            TimerMillis (unsigned long to);

            /** Function IsElapsed ********************************************************
            **
            **  Function checks whether the given Timer is done or not.
            **
            **  Parameters: void - none
            **  Returns:    DONE        - if timeout reached (true),
            **              NOT_DONE    - if timeout not yet reached (false).
            *******************************************************************************/
            bool IsElapsed ();

            /** Function IsActive *********************************************************
            **
            **  Function checks whether the given Timer is active or not.
            **
            **  Parameters: void - none
            **  Returns:    ACTIVE      - the timer is active (TRUE),
            **              NOT_ACTIVE  - the timer is not active (FALSE).
            *******************************************************************************/
            bool IsActive ();

            /** Function Reset ************************************************************
            **
            **  Function 'resets' and activates timer.
            **
            **  Parameters: void - none
            **  Returns:    void - nothing
            *******************************************************************************/
            void Reset ();

            /** Function Start ************************************************************
            **
            **  Function activates timer.
            **
            **  Parameters: void - none
            **  Returns:    DONE        - if timeout reached (true),
            **              NOT_DONE    - if timeout not yet reached (false).
            *******************************************************************************/
            void Start ();
            
            /** Function Stop *************************************************************
            **
            **  Function dectivates Timer.
            **
            **  Parameters: void - none
            **  Returns:    DONE        - if timeout reached (true),
            **              NOT_DONE    - if timeout not yet reached (false).
            *******************************************************************************/
            void Stop ();
            

            /** Function Set **************************************************************
            **
            **  Set a new timeout value at runtime.
            **
            **  Parameters: unsigned long
            **              the new timeout value should, be greater than 0, if value
            **              is < 0 the function will continue using the old value.
            **  Returns:    void - nothing
            *******************************************************************************/
            void Set (unsigned long to);

           
            /** Function Get **************************************************************
            **
            **  Retrieves the current millis value.
            **
            **  Parameters: void - none
            **  Returns:    unsigned long - the current value of the millis counter.
            *******************************************************************************/
            unsigned long Get ();


            /** Function GetTimeout ********************************************************
            **
            **  Function returns this instances target timeout value.
            **
            **  Parameters: void - none
            **  Returns:    unsigned long - this instances timeout value.
            *******************************************************************************/ 
            unsigned long GetTimeout();


            /** Function GetDelta *********************************************************
            **
            **  Function returns elapsed millis since last checking.
            **
            **  Parameters: void - none
            **  Returns:    unsigned long - the elapsed millis since last checking.
            *******************************************************************************/ 
            unsigned long GetDelta();


            /** Function GetDeltaToTarget *************************************************
            **
            **  Function returns delta of current millis to target.
            **
            **  Parameters: void - none
            **  Returns:    unsigned long - delta millis to target.
            *******************************************************************************/ 
            unsigned long GetDeltaToTarget();


            /** Function GetLastMillis ****************************************************
            **
            **  Function returns millis since last checking.
            **
            **  Parameters: void - none
            **  Returns:    unsigned long - millis since last checking.
            *******************************************************************************/ 
            unsigned long GetLastMillis ();

            #ifdef DEBUG
            /** Function GetDebugCounter **************************************************
            **
            **  Function returns a counter that increments everytime the method IsElapsed()
            **  is called.
            **
            **  Parameters: void - none
            **  Returns:    unsigned long - millis since last checking.
            *******************************************************************************/ 
                unsigned long GetDebugCounter ();
            #endif
        private:
            bool            _timer_active;
            unsigned long   _timeout;
            unsigned long   _last_millis;
            unsigned long   _dif;
            #ifdef DEBUG
                unsigned long   _debug_counter;
            #endif
    };
#endif // #ifdef TIMER_MILLIS_H_

