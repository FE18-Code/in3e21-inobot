#define IR_FREQ 38000

int irDetect(int irLedPin, int irReceiverPin){
  tone(irLedPin, IR_FREQ, 8);
  delay(1);
  return digitalRead(irReceiverPin);
}

void ir_init(){
  tone(TONE_PIN, 3000, 250);
  
  pinMode(IR_LED_LEFT, OUTPUT);
  pinMode(IR_RCV_LEFT, INPUT);
  pinMode(IR_LED_RIGHT, OUTPUT);
  pinMode(IR_RCV_RIGHT, INPUT);
}

void ir_to_serial() {
  int irState;
  
  irState=irDetect(IR_LED_LEFT, IR_RCV_LEFT); // left sensor 
  Serial.print(irState);  
  Serial.println(" > Left sensor");
  delay(100); 
  
  irState=irDetect(IR_LED_RIGHT, IR_RCV_RIGHT); // right sensor 
  Serial.print(irState); 
  Serial.println(" > IR Right sensor");
  delay(100); 
}
