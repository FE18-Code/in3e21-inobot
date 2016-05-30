#include <Servo.h>          // Include servo library

Servo servoLeft;            // Declare left servo
Servo servoRight;           // Declare right servo

int servos_vitesse;
const int SERVO_VITESSE_STOP=1500;

void setup() {                                // Built in initialization block
 
  // servos init
  servoLeft.attach(13);      // Attach left signal to pin 13
  servoRight.attach(12);      // Attach left signal to pin 12

//  // définition du sens
//  servoLeft.writeMicroseconds(400); // .4 ms stay-still signal 
//  servoRight.writeMicroseconds(400); // .4 ms stay-still signal
//
//  delay(3000);
//
//  // définition du sens
//  servoLeft.writeMicroseconds(2300); // 2.3 ms stay-still signal
//  servoRight.writeMicroseconds(2300); // 2.3 ms stay-still signal
//
//  delay(3000);
//
//  // définition du sens
//  servoLeft.writeMicroseconds(1500);         // Pin 13 stay still
//  servoRight.writeMicroseconds(1500);        // Pin 12 stay still
//
//
//  delay(3000);
 
}//setup

void loop(){                                 // Main loop auto-repeats
  servo_stop();
  
  servos_setVitesse(50);//vitesse 1500+-200
  
  delay(4000);
  
  tout_droit();
  
  delay(2000);
  
  servo_stop();
  
  delay(3000);
  
  servos_setVitesse(200);
  
  droite();
  
  servos_setVitesse(50);
  
  delay(500);
  
  servo_stop();
  
  delay(3000);
  
  gauche();
  
  delay(1000);
  
  

}//loop

void servo_stop(){
  servoLeft.writeMicroseconds(SERVO_VITESSE_STOP);         // Pin 13 stay still
  servoRight.writeMicroseconds(SERVO_VITESSE_STOP);        // Pin 12 stay still
 }
 
 void tout_droit(){
  servoLeft.writeMicroseconds(SERVO_VITESSE_STOP+servos_vitesse);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(SERVO_VITESSE_STOP-servos_vitesse);        // 1.3 ms -> clockwise
  //range = 1300 - 1700
 }

void droite(){
  servoLeft.writeMicroseconds(SERVO_VITESSE_STOP+servos_vitesse); // 2.3 ms stay-still signal
  servoRight.writeMicroseconds(SERVO_VITESSE_STOP+servos_vitesse); // 2.3 ms stay-still signal
  
 }
  
void gauche(){
  servoLeft.writeMicroseconds(SERVO_VITESSE_STOP-servos_vitesse); // 2.3 ms stay-still signal
  servoRight.writeMicroseconds(SERVO_VITESSE_STOP-servos_vitesse); // 2.3 ms stay-still signal
  
 }
 
 int servos_setVitesse(int vitesse){
   int retVal=-1;
   
   if(vitesse>200){
     vitesse=200;// trop grand
     retVal=-2;// out of range
   }else if(vitesse<0){
     vitesse=0;// trop petit
     retVal=-2;// out of range
   }
   
   servos_vitesse=vitesse;
   
   
   return retVal;
 }
 
 
