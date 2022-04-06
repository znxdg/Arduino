 int test = A3;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int Test = analogRead(test);
  Serial.println(Test, DEC);
  delay(1000);
}
