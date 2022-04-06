void setup() {
pinMode (9,OUTPUT);
pinMode (10,OUTPUT);
pinMode (11,OUTPUT);
}

void loop() {
analogWrite(9,250);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
delay(2000);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
delay(1000);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
delay(2000);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
delay(1000);

}
