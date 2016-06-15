#include "RobotServo.h"

const int SERVO_LEFT_PIN=11;
const int SERVO_RIGHT_PIN=12;
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

  rServoLeft.init(SERVO_LEFT_PIN,false);
  rServoRight.init(SERVO_RIGHT_PIN,true);
}//setup

void loop(){
  servo_stop();
  delay(500);
  
  /* tout_droit(); */
  rServoLeft.s_forward(50);
  rServoRight.s_forward(50);
  
  /* gauche(); */
  rServoLeft.s_forward(200);
  rServoRight.s_stop();
  delay(500);

  /* droite(); */
  rServoLeft.s_stop();
  rServoRight.s_forward(200);
  delay(500);
  
  /* tout_droit(); */
  rServoLeft.s_forward(100);
  rServoRight.s_forward(100);
  led();
  delay(3000);

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

