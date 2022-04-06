int a = 0;
int b = 0;
int c = 0;
int d = 0;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);  //光敏
}
void loop() {
  a = digitalRead(A0);
  b = digitalRead(A1);
  c = digitalRead(A2);
  d = analogRead(A3);
  if ( d < 600 ){
    digitalWrite(
  }
}
