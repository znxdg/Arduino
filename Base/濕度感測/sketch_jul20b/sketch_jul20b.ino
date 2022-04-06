const int buzzerPin = 8;
const int analogIn = A0;
const int highAlertVal = 400;
const int lowAlertVal = 200;
int wetVal =0;
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  wetVal = analogRead(analogIn);
  Serial.println(wetVal);
  if( wetVal > lowAlertVal){
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);

}
