#include <motor.h>
#include <pigpio.h>
#include <stdio.h> 
#include <stdlib.h>

Motor leftMotor;
Motor rightMotor;

leftMotor.setMotorPins(13,6,5);
rightMotor.setMotorPins(20,16,12);

leftMotor.initMotor();
rightMotor.initMotor();

void forward(int speed){

    leftMotor.setMotorMode(2);
    rightMotor.setMotorMode(2);

    leftMotor.setMotorSpeed(speed);
    rightMotor.setMotorSpeed(speed);

}

void backward(int speed){

    leftMotor.setMotorMode(1);
    rightMotor.setMotorMode(1);

    leftMotor.setMotorSpeed(speed);
    rightMotor.setMotorSpeed(speed);

}

void stop(){
    leftMotor.setMotorMode(0);
    rightMotor.setMotorMode(0);
}

void turnLeft(){
    leftMotor.setMotorMode(0);
    rightMotor.setMotorMode(2);

    leftMotor.setMotorSpeed(128);
}

void turnRight(){
    leftMotor.setMotorMode(2);
    rightMotor.setMotorMode(0);

    rightMotor.setMotorSpeed(128);
}
