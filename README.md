# ArduinoMillisTimer
The purpose of this little class is to simplify access to the Arduino Millis counter and make it accessible in a structured way just like a real timer. The Timer class (TimerMillis) provides an object with functionality to start, stop, check and reset a timer.
If DEBUG is defned it exposes some debug counters/timers for debugging purposes.

## How it works
The TimerMillis class exposes an external object called TM.
It provides the following methods:
- **TimerMillis (UL timeout)** this method initialises the timeout for this specific timer object;
- **IsElapsed ()** this method returns a boolean whether the specific timer has elapsed **(TRUE)** or not **(FALSE)**
- **Reset ()** this method restes the timer to its defined time out and starts counting from 0 again
- **Start ()** this method starts the timer
- **Stop ()** this method stops the timer
- **Set (UL timeout)** this method allows the program to set a different timeout value then defined in TimerMillis call
- **Get ()** this method returns the actual millis value
- **GetTimeout()** this method returns the value set as the timeout
- **GetDelta()** this method returns teh difference between the current millis count and teh target tieout
- **GetLastMillis ()** this method returns the last millis count e.g. after a reset() was issued 

