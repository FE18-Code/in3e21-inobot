/*
  RobotServo.h - Library for servo ctrl
*/

#ifndef RobotServo_h
#define RobotServo_h

#include "Arduino.h"
#include <Servo.h>

class RobotServo{
  
  private:
    /* class consts */
    static const int _SPEEDSTOP_USPULSE=1500;
    static const int _SPEEDMAX_USPULSE=200;
    static const int _SPEED_KEEP_SAME=-1;

    /* private class vars */
    Servo _servo;
    int _s_speed;
    boolean _servo_reversed;

    /* private funcrions */
    void s_set_speed(int s_speed);

  public:
    /* public functions */
    void init(int pin, boolean reversed);
    void s_stop();
    void s_forward(int s_speed=_SPEED_KEEP_SAME);
    void s_backward(int s_speed=_SPEED_KEEP_SAME);
    
};//class
#endif

