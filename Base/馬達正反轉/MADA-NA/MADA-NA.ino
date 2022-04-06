
void setup() {
  pinMode(4,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  analogWrite(9,150);
  analogWrite(6,150);
  boolean val = digitalRead(4);
  if (val) {
  digitalWrite(7,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(8,LOW);
  digitalWrite(10,HIGH);
  delay(2000);
  
  } else {
  digitalWrite(7,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(10,LOW);
  delay(2000);
  
  }
  
  
}
