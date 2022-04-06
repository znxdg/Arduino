const int led = 3;
void setup() {
  
}

void loop() {
  for(int fadeValue = 0;fadeValue <= 70; fadeValue = fadeValue + 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
  for(int fadeValue = 70;fadeValue >= 0; fadeValue = fadeValue - 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
  }
