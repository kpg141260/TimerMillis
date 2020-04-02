#include <timer.h>
#include "Arduino.h"
/*
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
*/
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
TimerMillis::TimerMillis (unsigned long to) {
    if (to > 1) {
        _timeout = to;
    }
    else {
        _timeout = TMR_DEFAULT_TO;
    }
    _timer_active = true;
    #ifdef DEBUG
        _debug_counter = 0;
    #endif
    _last_millis = millis();
}
/** Function IsElapsed ********************************************************
**
**  Function checks whether the given Timer is done or not.
**
**  Parameters: void - none
**  Returns:    DONE        - if timeout reached (true),
**              NOT_DONE    - if timeout not yet reached (false).
*******************************************************************************/
bool TimerMillis::IsElapsed (void) {
    if (_timer_active) {
        if (millis() < _last_millis) {
            _last_millis = millis();
        }
        _dif = millis() - _last_millis;
        if (_dif >= _timeout) {
            _last_millis = millis();
            #ifdef DEBUG
                _debug_counter++;
            #endif
            return true;
        }
        else
            return false;
    }
    return false;
}
/** Function Reset ************************************************************
**
**  Function 'resets' and activates timer.
**
**  Parameters: void - none
**  Returns:    void - nothing
*******************************************************************************/
void TimerMillis::Reset (void) {
    _timer_active = true;
    _last_millis = millis();
}
/** Function Start ************************************************************
**
**  Function activates timer.
**
**  Parameters: void - none
**  Returns:    DONE        - if timeout reached (true),
**              NOT_DONE    - if timeout not yet reached (false).
*******************************************************************************/
void TimerMillis::Start() {
    _timer_active = true;
}
/** Function Stop *************************************************************
**
**  Function dectivates Timer.
**
**  Parameters: void - none
**  Returns:    DONE        - if timeout reached (true),
**              NOT_DONE    - if timeout not yet reached (false).
*******************************************************************************/
void TimerMillis::Stop (){
    _timer_active = false;
}
/** Function GetTimeout ***********************************************************
**
**  Function returns this Timers timeout value - Getbimeoutck.
**
**  Parameters: void - none
**  Returns:    unsigned long - this timers time out value.
*******************************************************************************/
unsigned long TimerMillis::GetTimeout (void) {
    return _timeout;
}
/** Function Set **************************************************************
**
**  Set a new timeout value at runtime, the value could be retrieved through
**  a menu or serial input.
**
**  Parameters: unsigned long
**              the new timeout value should, be greater than 0, if value
**              is < 0 the function will continue using the old value.
**  Returns:    void - nothing
*******************************************************************************/
void TimerMillis::Set (unsigned long to) {
    if (to > 1) {
        _timeout = to;
    }
    else {
        _timeout = _timeout;
    }
    _last_millis = millis();
}

/******************************************************************************
**  The follwing functions where intruduced for troubleshooting of an initial 
**  issue I had with the class, I left them in, but you may just delete them or 
**  comment them out.
*******************************************************************************/
unsigned long TimerMillis::Get (void) {
    return millis ();
}
/* Functions returns value (difference) of millis - _last_millis */
unsigned long TimerMillis::GetDelta (void) {
    return _dif;
}
/* Function returns value of _last_millis */
unsigned long TimerMillis::GetLastMillis (void) {
    return _last_millis;
}
#ifdef DEBUG
    unsigned long TimerMillis::GetDebugCounter (void) {
        return _debug_counter;
    }
#endif
