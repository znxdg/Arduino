int x =0;
int y=0;
void setup() {
  pinMode(2,INPUT);

}

void loop() {
 x= digitalRead(2);
 if(x==HIGH){
  if(y<70)y=y+10;
 }
 else{
  if(y>0)y=y-10;
 }
analogWrite(3,y);
delay(100);
}
