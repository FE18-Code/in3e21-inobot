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

//const int pingPin = 7;
const int US_TRIG_PIN=5;
const int US_ECHO_PIN=6;

void setup(){
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(US_TRIG_PIN, OUTPUT);
  pinMode(US_ECHO_PIN, INPUT);
}

void loop(){
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

  // convert the time into a distance
  //distance=microsecondsToCentimeters(duration);

  Serial.print(duration);
  Serial.println(" us");
  //Serial.print(distance);
  //Serial.println(" cm");

  delay(100);
}

unsigned long microsecondsToCentimeters(unsigned long microseconds){
  // see HC-SR04 documentation
  return microseconds ;/// 58;
}
