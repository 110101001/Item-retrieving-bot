#include "motor.h"
#include <pigpio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SPEED 255
#define BURST_TIME 60000

void initRobot(){
    gpioInitialise();
    initialMotors();
}

void moveForward(int speed){
    //speed 0-255
    setLeftMode(2);
    setRightMode(1);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    usleep(BURST_TIME);
    setLeftSpeed(speed);
    setRightSpeed(speed);
}

void moveBackward(int speed){
    setLeftMode(1);
    setRightMode(2);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    usleep(BURST_TIME);
    setLeftSpeed(speed);
    setRightSpeed(speed);
}

void turnLeft(int speed){
    setLeftMode(1);
    setRightMode(1);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    usleep(BURST_TIME);
    setLeftSpeed(0);
    setRightSpeed(speed);
}

void turnRight(int speed){
    setLeftMode(2);
    setRightMode(2);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    usleep(BURST_TIME);
    setLeftSpeed(speed);
    setRightSpeed(0);
}

void robotStop(){
    stop();
}
