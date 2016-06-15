/*
  RobotServo.cpp - Library for servo ctrl
*/

#include "RobotServo.h"

void RobotServo::init(int pin, boolean reversed){
  this->_servo_reversed=reversed;
  this->_s_speed=_SPEEDMAX_USPULSE;
  this->_servo.attach(pin);
  this->s_stop();
}

void RobotServo::s_stop(){
  this->_servo.writeMicroseconds(_SPEEDSTOP_USPULSE);
}

void RobotServo::s_set_speed(int s_speed){
  if((s_speed>0)||(s_speed<=_SPEEDMAX_USPULSE)){
    this->_s_speed=s_speed;/* checks param &  same speed if out of range */
    
    if(this->_servo_reversed==true){
      this->_s_speed=-this->_s_speed;
    }
  }/* out of range : keep same speed */
}

void RobotServo::s_forward(int s_speed){
  this->s_set_speed(s_speed);
  this->_servo.writeMicroseconds(_SPEEDSTOP_USPULSE+this->_s_speed);
}

void RobotServo::s_backward(int s_speed){
  this->s_set_speed(s_speed);
  this->_servo.writeMicroseconds(_SPEEDSTOP_USPULSE-this->_s_speed);
}

