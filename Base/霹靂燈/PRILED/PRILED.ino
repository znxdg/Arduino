const int firstLedPin = 7;
const int lastLedPin = 13;
void setup() {
  for(int led = firstLedPin; led <=lastLedPin; led = led + 1){
    pinMode(led,OUTPUT);
  }
}

void loop() {
  for(int led = firstLedPin; led<= lastLedPin; led= led+1){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led, LOW);
  }
for (int led = lastLedPin; led >= firstLedPin; led= led - 1) {
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led, LOW);
}
}
