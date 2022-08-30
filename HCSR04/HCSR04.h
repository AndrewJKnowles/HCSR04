/*  HCSR04 Library
*   ==============
*   Provided as is without any gaurentees.
*  
*   Authored by:            Andrew knowles       
*   Date:                   08/2022
*   Collaberators:          
*   Version:                1.0
*   Revision Date:          
*   MBED Studio Version:    1.4.4
*   MBED OS Version:        6.14.0  */

#ifndef HCSR04_h
#define HCSR04_h

#include "mbed.h"

#define SPEEDOFSOUND 0.03432

class HCSR04{
    public:
        // create object
        HCSR04(PinName const triggerPin, PinName const echoPin);

        //initialise sensor
        void init();

        //returns the measured distance in centimeters
        float getDistanceCm();

        //returns the measured distance in inches
        float getDistanceInch();

        //returns the measured pulse time
        float getPulseTime();


    private:
        Timer pulseTimer;
        DigitalOut trigger;
        DigitalIn echo;

        float pulseTime;
        float distance_cm;
        float distance_inch;

        //sends a trigger signal to the sensor
        void sendTrigger();

        //measures the pulse time
        void pulseMeasurement();
};

#endif
