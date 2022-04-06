const int bluepin=9;          
const int redpin=10;
const int greenpin=11;
void setup() {
}
void loop() {
 int bluevalue=0;
 int redvalue=0;
 int greenvalue=0;
 for(redvalue=1; redvalue<=255; redvalue=redvalue+1){
 analogWrite(redpin, redvalue);
 delay(10);
}
 for(redvalue=255; redvalue>=0; redvalue=redvalue-1){
  analogWrite(redpin,redvalue);
  delay(10);
 }
 for(greenvalue=1; greenvalue<=150; greenvalue=greenvalue+1){
  analogWrite(greenpin,greenvalue);
  delay(10);
 }
 for(greenvalue=150; greenvalue>=0; greenvalue=greenvalue-1){
  analogWrite(greenpin,greenvalue);
  delay(10);
 }
 for(bluevalue=1; bluevalue<=255; bluevalue=bluevalue+1){
  analogWrite(bluepin,bluevalue);
  delay(10);
   }
   for(bluevalue=255; bluevalue>=0; bluevalue=bluevalue-1){
    analogWrite(bluepin,bluevalue);
    delay(10);
   }
   for(int i=1; i<=100; i=i+1){
    redvalue=random(1,30);
    greenvalue=random(1,20);
    bluevalue=random(1,50);

    analogWrite(redpin,redvalue);
    analogWrite(greenpin,greenvalue);
    analogWrite(bluepin,bluevalue);
    delay(500);
   }
    analogWrite(redpin,0);
    analogWrite(greenpin,0);
    analogWrite(bluepin,0);
}
