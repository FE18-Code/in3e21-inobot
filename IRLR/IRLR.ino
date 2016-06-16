const int TONE_PIN=4;
const int IR_LED_LEFT=9;
const int IR_RCV_LEFT=10;
const int IR_LED_RIGHT=2;
const int IR_RCV_RIGHT=3;

int irDetect(int irLedPin, int irReceiverPin, long frequency){
  tone(irLedPin, frequency, 8);
  delay (1);
  return digitalRead(irReceiverPin);
//  delay(1);
}

void setup() {
  
  tone(TONE_PIN, 3000, 1000);  
  delay(1000);
  
  pinMode(IR_LED_LEFT, OUTPUT);
  pinMode(IR_RCV_LEFT, INPUT);  
  
  pinMode(IR_LED_RIGHT, OUTPUT);
  pinMode(IR_RCV_RIGHT, INPUT);  
  
  Serial.begin(9600);
}



void loop() {
  int irLeft = irDetect(IR_LED_LEFT, IR_RCV_LEFT, 38000); // left sensor 
  Serial.print(irLeft);  
  Serial.println(" Capteur gauche ");
  delay(100); 
  
  int irRight = irDetect(IR_LED_RIGHT, IR_RCV_RIGHT, 38000); // right sensor 
  Serial.print(irRight); 
  Serial.println(" Capteur droite ");
  delay(100); 
}
