#include <motor.h>
#include <motor_control.h>
#include <robot_control.h>
#include <pigpio.h>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>

int main(){
    gpioInitialise();

    gpioSetMode(13,PI_OUTPUT);

    gpioPWM(13,128);

    gpioSetPWMfrequency(13,50);

    delay(5000);

    gpioTerminate();

    return 0;
}