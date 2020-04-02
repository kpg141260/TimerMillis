#include <Arduino.h>
#include "timermillis.h"

TimerMillis::TimerMillis (unsigned long to) {
    if (to > 1) {
        _timeout = to;
    }
    else {
        _timeout = DEFAULT_TO;
    }
    _timer_active = ACTIVE;
    #ifdef DEBUG
        _debug_counter = 0;
    #endif
    _last_millis = millis();
}

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
            return ELAPSED;
        }
        else
            return NOT_ELAPSED;
    }
    return NOT_ACTIVE;
}

bool TimerMillis::IsActive (void) {
    return _timer_active;
}

void TimerMillis::Reset (void) {
    _timer_active = ACTIVE;
    _last_millis = millis();
}

void TimerMillis::Start() {
    _timer_active = ACTIVE;
}

void TimerMillis::Stop (){
    _timer_active = NOT_ACTIVE;
}

void TimerMillis::Set (unsigned long to) {
    if (to > 1) {
        _timeout = to;
    }
    else {
        _timeout = _timeout;
    }
    _last_millis = millis();
}

unsigned long TimerMillis::Get (void) {
    return millis ();
}

unsigned long TimerMillis::GetTimeout (void) {
    return _timeout;
}

/* Functions returns value (difference) of millis - _last_millis */
unsigned long TimerMillis::GetDelta (void) {
    return _dif;
}

unsigned long TimerMillis::GetDeltaToTarget (void) {
    return _timeout - _dif;
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
