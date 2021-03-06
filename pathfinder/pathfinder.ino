#include <Servo.h>
#include "RobotServo.h"

// state machine
#define STATE_INIT 0
#define STATE_STOP 1
#define STATE_FORWARD 2
#define STATE_BACKWARD 3
#define STATE_RIGHT 4
#define STATE_LEFT 5
#define STATE_CHECK_ULTRAS 6

int stm_state;

const int TONE_PIN = 4; //buzzer
const int US_TRIG_PIN = 5; //ultrasonic input
const int US_ECHO_PIN = 6; //ultrasonic output
const int IR_LED_LEFT=9; //ir left input
const int IR_RCV_LEFT=10; //ir left output
const int IR_LED_RIGHT=2; //ir right input
const int IR_RCV_RIGHT=3; //ir right output
const int SERVO_LEFT_PIN = 11; //servo
const int SERVO_RIGHT_PIN = 12; //servo
const int LED13_PIN = 13; //captain obvious will rule the world !

//servos
RobotServo rServoLeft;
RobotServo rServoRight;

void setup() {
  pinMode(LED13_PIN, OUTPUT);
  led();

  us_init(); //ultrasonic sensor init
  ir_init(); //ir sensors init
  rServoLeft.init(SERVO_LEFT_PIN, false);
  rServoRight.init(SERVO_RIGHT_PIN, true);

  stm_state = STATE_INIT;
  Serial.begin(9600);
}//setup

void loop() {
  delay(50);

  switch (stm_state) {
    case STATE_INIT:

      stm_state = STATE_CHECK_ULTRAS;

      break;

    case STATE_STOP:

      servo_stop();
      stm_state = STATE_CHECK_ULTRAS;

      break;

    case STATE_FORWARD:

      avancer();
      stm_state = STATE_CHECK_ULTRAS;

      break;

    case STATE_BACKWARD:

      reculer();
      stm_state = STATE_CHECK_ULTRAS;

      break;

    case STATE_RIGHT:

      droite();
      stm_state = STATE_CHECK_ULTRAS;

      break;

    case STATE_LEFT:

      gauche();
      stm_state = STATE_CHECK_ULTRAS;

      break;

    case STATE_CHECK_ULTRAS:

      distance();

      break;

    default:

      servo_stop();
      stm_state = STATE_CHECK_ULTRAS;
      break;
  }

}

void distance() {
  int us_distance;
  us_distance = (int)get_us_distance(false);
  Serial.print("Distance : ");
  Serial.println(us_distance);
  if (us_distance <= 5) {
    stm_state = STATE_RIGHT;
  } else {
    stm_state = STATE_FORWARD;
  }
}


/* droite(); */
void droite() {
  rServoLeft.s_backward(200);
  rServoRight.s_forward(200);
}


void avancer() {
  /* tout_droit(); */
  rServoLeft.s_forward(50);
  rServoRight.s_forward(50);
}

void reculer() {
  /* reculer(); */
  rServoLeft.s_backward(50);
  rServoRight.s_backward(50);
}

void gauche() {
  /* gauche(); */
  rServoLeft.s_forward(200);
  rServoRight.s_stop();

}

void servo_stop() {
  rServoLeft.s_stop();
  rServoRight.s_stop();
}

void led() {
  digitalWrite(LED13_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(450);              // wait
  digitalWrite(LED13_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(50);              // wait
}

