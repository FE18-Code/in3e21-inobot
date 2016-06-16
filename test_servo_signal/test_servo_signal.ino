#include <Servo.h>
#include "RobotServo.h"

const int TONE_PIN=4;//buzzer
const int US_TRIG_PIN=5;//ultrasonic input
const int US_ECHO_PIN=6;//ultrasonic output
const int SERVO_LEFT_PIN=11;//servo
const int SERVO_RIGHT_PIN=12;//servo
const int LED13_PIN=13;//captain obvious will rule the world !

//servos
RobotServo rServoLeft;//(SERVO_LEFT_PIN,false);
RobotServo rServoRight;

void setup() {
  pinMode(LED13_PIN, OUTPUT);
  digitalWrite(LED13_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(450);              // wait for a second
  digitalWrite(LED13_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(50);              // wait for a second

  us_init();
  rServoLeft.init(SERVO_LEFT_PIN,false);
  rServoRight.init(SERVO_RIGHT_PIN,true);
  Serial.begin(9600);
}//setup

void loop(){
  int us_distance;
  //servo_stop();
  delay(50);
  
  us_distance=(int)get_us_distance();
  Serial.print("Distance : ");
  Serial.println(us_distance);
  
  if(us_distance<=5){
    rServoLeft.s_backward(100);
    rServoRight.s_backward(100);
  }else{
    rServoLeft.s_forward(50);
    rServoRight.s_forward(50);
  }
  /* droite(); */
  //rServoLeft.s_backward(200);
  //rServoRight.s_forward(200);
  //delay(1000); 
  //}else{
      
  /* tout_droit(); */
  //rServoLeft.s_forward(50);
  //rServoRight.s_forward(50);
  //delay(1000);
  
  /* gauche(); */
  //rServoLeft.s_forward(200);
  //rServoRight.s_stop();
  //delay(500);

  /* droite(); */
  //rServoLeft.s_stop();
  //rServoRight.s_forward(200);
  //delay(500);
  //}


}//loop

void servo_stop(){
  rServoLeft.s_stop();
  rServoRight.s_stop();
}

void led(){
  digitalWrite(LED13_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(450);              // wait for a second
  digitalWrite(LED13_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(50);              // wait for a second  
}

