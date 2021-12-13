#include "motor.h"
#include <pigpio.h>
#include <time.h>
#include <unistd.h>
#include "timer.h"
#include "robot_control.h"

#define MAX_SPEED 255
#define BURST_TIME 60000

static Timer t;

void initRobot(){
    gpioInitialise();
    initialMotors();
}

void moveForward(int tm){
    //tm 0-255
    setLeftMode(2);
    setRightMode(1);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    t.setTimeout([&]() {
        robotStop();
        t.stop();
    }, tm); 
}

void moveBackward(int tm){
    setLeftMode(1);
    setRightMode(2);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    t.setTimeout([&]() {
        robotStop();
        t.stop();
    }, tm); 
}

void turnLeft(int tm){
    setLeftMode(1);
    setRightMode(1);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    t.setTimeout([&]() {
        robotStop();
        t.stop();
    }, tm); 
}

void turnRight(int tm){
    setLeftMode(2);
    setRightMode(2);
    setLeftSpeed(MAX_SPEED);
    setRightSpeed(MAX_SPEED);
    t.setTimeout([&]() {
        robotStop();
        t.stop();
    }, tm); 
}

void robotStop(){
    stop();
}
