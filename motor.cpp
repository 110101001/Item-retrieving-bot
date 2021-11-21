#include <pigpio.h>
#include <stdio.h> 
#include <stdlib.h>

//gpioSetMode(13, PI_OUTPUT);
//pinMode (23, OUTPUT)
// gpioTerminate();
// gpioWrite(13, PinValue)

#define HIGH 1
#define LOW 0

class Motor{

private:
    int motorPins[3];

public:
    void setMotorPins(int pwm, int A0, int A1){
        motorPins[0] = pwm;
        motorPins[1] = A0;
        motorPins[2] = A1;
    }

    void initMotor(){
        gpioSetMode(motorPins[0],PI_OUTPUT);
        gpioSetMode(motorPins[1],PI_OUTPUT);
        gpioSetMode(motorPins[2],PI_OUTPUT);
        
        /*
            set default dutycycle 0
            set default frequency 50Hz
            using default pwm range 255
        */
        gpioPWM(motorPins[0],0);//0 duty cycle
        gpioSetPWMfrequency(motorPins[0],50);// set frequency 50Hz

    }

    void setMotorMode(int mode){
        /*
            mode = 0, motor stops
            mode = 1, clockwise
            mode = 2, counterclockwise
        */
        switch(mode){
            case 0:
                gpioWrite(motorPins[0],LOW);
                break;
            case 1:
                gpioWrite(motorPins[0],HIGH);
                gpioWrite(motorPins[1],HIGH);
                gpioWrite(motorPins[2],LOW);
                break;
            case 2:
                gpioWrite(motorPins[0],HIGH);
                gpioWrite(motorPins[1],LOW);
                gpioWrite(motorPins[2],HIGH);
                break;
            default:
                break;
        }
    }

    void setMotorSpeed(int speedValue){
        //set speed by adjusting duty cycle, 0 < speedValue < 255
        if(speedValue > 255){
            speedValue = 255;
        }else if(speedValue < 0){
            speedValue = 0;
        }

        gpioPWM(motorPins[0],speedValue);

    }

    void setFrequency(int f){
        gpioSetPWMfrequency(motorPins[0],f);
    }

}
