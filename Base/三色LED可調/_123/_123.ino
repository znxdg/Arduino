const int r1 = A2;
const int r2 = A3;
const int r3 = A4;
const int bluepin=9;          
const int redpin=10;
const int greenpin=11;
void setup() {
}

void loop() {
  int R1 = analogRead(r1);
  int R2 = analogRead(r2);
  int R3 = analogRead(r3);
  analogWrite(greenpin,R1/4);
  analogWrite(bluepin,R2/4);
  analogWrite(redpin,R3/4);
}
