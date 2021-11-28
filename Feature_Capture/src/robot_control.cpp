#include "motor.h"
#include <pigpio.h>
#include <time.h>
#include <unistd.h>

void initRobot(){
    initialMotors();
}

void moveForward(int speed){
    //speed 0-255
    setLeftMode(2);
    setRightMode(1);
    setLeftSpeed(speed);
    setRightSpeed(speed);
}

void moveBackward(int speed){
    setLeftMode(1);
    setRightMode(2);
    setLeftSpeed(speed);
    setRightSpeed(speed);
}

void turnLeft(int speed){
    setLeftMode(1);
    setRightMode(1);
    setLeftSpeed(speed);
    setRightSpeed(speed);
}

void turnRight(int speed){
    setLeftMode(2);
    setRightMode(2);
    setLeftSpeed(speed);
    setRightSpeed(speed);
}

void robotStop(){
    stop();
}