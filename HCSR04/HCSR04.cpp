#include "mbed.h"
#include "HCSR04.h"

//Public functions
HCSR04::HCSR04(PinName const triggerPin, PinName const echoPin) : trigger(triggerPin), echo(echoPin){};

void HCSR04::init(){
    pulseTimer.reset();                             //reset pulse timer
    trigger.write(0);                               //set trigger signal to low
    distance_cm = 0.0f;                             //initialise value
    distance_inch = 0.0f;                           //initialise value
}

float HCSR04::getDistanceCm(){
    sendTrigger();
    pulseMeasurement();

    distance_cm = pulseTime * SPEEDOFSOUND / 2.0f;

    //check if out of range
    if(distance_cm > 400.0f){
        distance_cm = 0.0f;
    }
    return distance_cm;
}

float HCSR04::getDistanceInch(){
    distance_inch = getDistanceCm()/2.54f;          //convert cm to inch by dividing by 2.54
    return distance_inch;
}

float HCSR04::getPulseTime(){
    return pulseTime;
}

//private functions
void HCSR04::sendTrigger(){
    trigger.write(1);                               //send trigger pulse (high)
    wait_us(10);                                    //allow for full duration of pulse
    trigger.write(0);                               //reset trigger signal (low)
}

void HCSR04::pulseMeasurement(){
    while(echo.read() == 0){}                       //wait to receive echo signal
    pulseTimer.start();                             //start pulse timer
    while(echo.read() == 1){}                       //wait for end of echo signal
    pulseTimer.stop();                              //stop pulse timer
    pulseTime = pulseTimer.elapsed_time().count();  //record duration of echo pulse
    pulseTimer.reset();                             //reset timer
}