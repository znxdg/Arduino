const int variable = A2;
const int led = 9;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int sensorValue = analogRead(variable);
analogWrite(led,sensorValue/4);
delay(150);
}
