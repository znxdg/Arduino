int x = 0;    //以使用腳位:0,1,2,3,4,5,6,7,8,9,10,11,12,13
int y = 0;
int z = 0;
int tt = 0;
int fadeValue = 0;
byte index = 0;
const int led = 10;
const byte LEDs[3] = {B1111110,B0110000,B1101101};
 void setup(){
  pinMode(7,INPUT);    //呼吸燈開關
  pinMode(8,INPUT);    //倒退開關
  pinMode(9,OUTPUT);   //馬達智能腳
  //pinMode(11,OUTPUT);  // 總開關
  pinMode(12,OUTPUT);  //馬達輸出1
  pinMode(13,OUTPUT);  //馬達輸出2
  DDRD = B11111111;    //0~6腳為七段
}
void loop() {
  analogWrite(9,150);
  x= digitalRead(7);
  y= digitalRead(8);
  //z= digitalRead(11);
  //呼吸燈
  if(x==HIGH){
  for(;fadeValue <= 255; fadeValue = fadeValue + 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
 }
  //馬達正反轉(含七段)
  //正轉
  if(z==HIGH & y == LOW){
  PORTD = LEDs[1];
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  if(y == LOW){
    tt++;
    delay(1);
  } 
  } else if (z==HIGH & y == HIGH){
    PORTD = LEDs[2];
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(tt);
  }
}
