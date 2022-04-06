int x = 0;    //以使用腳位:0,1,2,3,4,5,6,7,8,9,10,12,13
int y = 0;
int z = 0;
int tt = 0;
int fadeValue = 0;
int sp = 0;
const int led = 9;
const int variable = A0;
const byte LEDs[3] = {B1111110,B0110000,B1101101};
 void setup(){
  pinMode(11,INPUT);    //呼吸燈開關
  pinMode(8,INPUT);    //倒退開關
  pinMode(10,OUTPUT);   //馬達智能腳
  pinMode(12,OUTPUT);  //馬達輸出1
  pinMode(13,OUTPUT);  //馬達輸出2
  DDRD = B11111111;    //0~6腳為七段
}
void loop() {
  x= digitalRead(11);
  y= digitalRead(8);
  z = analogRead(variable);
  analogWrite(10,sp);
  if ( z <= 400){
    sp = 100;
  } else{
    sp = 250;
  }
  //呼吸燈
  if(x==LOW){
  for(;fadeValue <= 255; fadeValue = fadeValue + 3)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
 }
  //馬達正反轉(含七段)
  //正轉
  if( y == LOW){
  PORTD = LEDs[1];
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  tt++;
  delay(1);
  } else {
  tt=tt/2;
  PORTD = LEDs[0];
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(1000);
  PORTD = LEDs[2];
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(tt);
  while(tt!=0){
    tt--;
    delay(1);
  }
  }

}
