int i;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(A5,INPUT);
}

void loop() {
  i = digitalRead(A5);
  Serial.println(i, DEC);
  delay(1000);
  if(i == 0){
    digitalWrite(2,LOW);
  } else {
    digitalWrite(2,HIGH);
  }
}
