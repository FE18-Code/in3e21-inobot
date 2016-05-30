#include <Servo.h>          // Include servo library

Servo servoLeft;            // Declare left servo
Servo servoRight;           // Declare right servo

void setup() {                                // Built in initialization block
 
  servoLeft.attach(13);      // Attach left signal to pin 13
  servoRight.attach(12);      // Attach left signal to pin 12

  // définition du sens
  servoLeft.writeMicroseconds(400); // .4 ms stay-still signal 
  servoRight.writeMicroseconds(400); // .4 ms stay-still signal

  delay(3000);

  // définition du sens
  servoLeft.writeMicroseconds(2300); // 2.3 ms stay-still signal
  servoRight.writeMicroseconds(2300); // 2.3 ms stay-still signal

  delay(3000);

  // définition du sens
  servoLeft.writeMicroseconds(1500);         // Pin 13 stay still
  servoRight.writeMicroseconds(1500);        // Pin 12 stay still

  servoLeft.detach();
  servoRight.detach();

  delay(500);

  servoLeft.attach(13);      // Attach left signal to pin 13
  servoRight.attach(12);      // Attach left signal to pin 12

  ///////////////////////////////////////////////////////////////////////////////////
  servoLeft.writeMicroseconds(1500);         // Pin 13 stay still
  delay(3000);
  servoLeft.writeMicroseconds(1700);         // Pin 13 stay still
  
  servoRight.writeMicroseconds(1500);        // Pin 12 stay still
  delay(3000);
  servoRight.writeMicroseconds(1300);
  ///////////////////////////////////////////////////////////////////////////////////
  
}//setup

void loop(){                                 // Main loop auto-repeats



}//loop
