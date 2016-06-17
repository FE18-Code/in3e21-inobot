/* Ping))) Sensor

   This sketch reads a PING))) ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.

   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* US_TRIG_PIN connection of the PING))) (start signal) attached to a digital pin
        * US_ECHO_PIN connection of the PING response (get distance) attached to a digital pin

 */

void us_init(){
  pinMode(US_TRIG_PIN, OUTPUT);
  pinMode(US_ECHO_PIN, INPUT);
}

long get_us_distance(boolean buzzer_output){
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  unsigned long duration, distance;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(US_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG_PIN, LOW);

  // Other pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration=pulseIn(US_ECHO_PIN, HIGH);

  if(duration==0){//ultrasonic err : sensor jammed
    if(buzzer_output==true){
      tone(TONE_PIN,7000,300);
    }
    
    pinMode(US_ECHO_PIN, OUTPUT);
    digitalWrite(US_ECHO_PIN, LOW);
    delay(150);//sensor needs 150ms to reset
    pinMode(US_ECHO_PIN, INPUT);
    
    if(buzzer_output==true){
      tone(TONE_PIN,8800,300);
    }
  }else{
    // convert the time into a distance
    distance=microsecondsToCentimeters(duration);
  }

  return distance;
}

unsigned long microsecondsToCentimeters(unsigned long microseconds){
  // see HC-SR04 documentation for pulse time <> distance ratio
  return microseconds/58.0;
}
