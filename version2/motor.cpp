#include <pigpio.h>

void initialMotors(){
    gpioSetMode(13,PI_OUTPUT);
    gpioSetMode(6,PI_OUTPUT);
    gpioSetMode(5,PI_OUTPUT);
    gpioSetMode(20,PI_OUTPUT);
    gpioSetMode(16,PI_OUTPUT);
    gpioSetMode(12,PI_OUTPUT);

    // gpioPWM(13,128);
    // gpioSetPWMfrequency(13,50);
    // gpioPWM(20,128);
    // gpioSetPWMfrequency(20,50);
}

void setLeftMode(int mode){
    switch(mode){
        case 0:
            gpioWrite(13,0);
            break;
        case 1:
            gpioPWM(13,128);
            gpioSetPWMfrequency(13,50);
            gpioWrite(6,1);
            gpioWrite(5,0);
            break;
        case 2:
            gpioPWM(13,128);
            gpioSetPWMfrequency(13,50);
            gpioWrite(6,0);
            gpioWrite(5,1);
            break;
        default:
            break;
    }
}

void setRightMode(int mode){
    switch(mode){
        case 0:
            gpioWrite(20,0);
            break;
        case 1:
            gpioPWM(20,128);
            gpioSetPWMfrequency(20,50);
            gpioWrite(16,1);
            gpioWrite(12,0);
            break;
        case 2:
            gpioPWM(20,128);
            gpioSetPWMfrequency(20,50);
            gpioWrite(16,0);
            gpioWrite(12,1);
            break;
        default:
            break;
    }
}

void setLeftSpeed(int speedValue){
    if(speedValue > 255){
        speedValue = 255;
    }else if(speedValue < 0){
        speedValue = 0;
    }
    gpioPWM(13,speedValue);
}

void setRightSpeed(int speedValue){
    if(speedValue > 255){
        speedValue = 255;
    }else if(speedValue < 0){
        speedValue = 0;
    }
    gpioPWM(20,speedValue);
}

void stop(){
    gpioWrite(13,0);
    gpioWrite(20,0);
}
