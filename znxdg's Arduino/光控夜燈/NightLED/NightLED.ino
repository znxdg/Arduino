const int r1 = A0;
const int led=9;
int a=0;
const int b=600;
void setup() {
  pinMode(led,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  a = analogRead(r1);
  if (a < b ) {
    digitalWrite(led,HIGH);
  }
  if (a > b ) {
    digitalWrite(led,LOW);
  }
}
