int fadeValue = 0;
const int variable = A0;
const int madasmart1 = 10;
const byte LEDs[3] = {B1111110,B0110000,B1101101}; 
int y =0;
int tt = 0;
void setup() {
 pinMode(8,INPUT);
}

void loop() {
  y= digitalRead(8);
  int sensorValue = analogRead(variable);
    analogWrite(madasmart1,150);
  if( y == LOW){
  PORTD = LEDs[1];
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  tt++;
  delay(1);
  } else {
  tt=tt/2;
  PORTD = LEDs[0];
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(1000);
  PORTD = LEDs[2];
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(tt);
  while(tt!=0){
    tt--;
    delay(1);
  }
  }
}
