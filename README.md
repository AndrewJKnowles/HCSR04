HCSR04 Ultrasonic sensor
========================

![HC-SR04-Ultrasonic-Sensor-Pinout-diagram](https://user-images.githubusercontent.com/87070974/187504950-af2e6a49-1ab2-4d53-8301-3601b72dcd2a.jpg)

Function:               Library created for interfacing the ultrasonic HCSR04 sensor with the MBED platform. The library was developed
                        using the STM Nucleo L476RG microcontroller.
                        
                        Public member functions:
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

Authored by:            Andrew knowles       
Date:                   08/2022
Collaberators:          
Version:                1.0
Revision Date:          
MBED Studio Version:    1.4.4
MBED OS Version:        6.14.0
