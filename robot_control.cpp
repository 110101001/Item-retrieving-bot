#include <motor.h>
#include <motor_control.h>
#include <pigpio.h>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>

void moveForwardSteps(int speed, int steps){
    while(steps>0){
        forward(speed);
        delay(1000);
        stop();
        delay(1000);
        steps--;
    }
}

void backForwardSteps(int speed, int steps){
    while(steps>0){
        backward(speed);
        delay(1000);
        stop();
        delay(1000);
        steps--;
    }
}

void robotTurnLeft(){
    turnLeft();
    delay(1000);
    stop();
}

void robotTurnRight(){
    turnRight();
    delay(1000);
    stop();
}

void robotStop(){
    stop();
}

