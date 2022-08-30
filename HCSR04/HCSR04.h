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