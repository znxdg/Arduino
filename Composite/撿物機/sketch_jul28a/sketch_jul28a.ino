int tt = 0;            //前進時間初始值
int sp = A3;            //蜂鳴器
int sw1 = 0;           //總開關
int sw2 = 0;           //前端感測
const int led = A2;    //待命燈
const int ledd = A4;   //閃爍LED
const byte LEDs[4] = {B1111110,B0110000,B1101101,B0000000};
void setup() {
  pinMode(A0,INPUT);   //總開關
  pinMode(A1,INPUT);   //前端感測開關
  pinMode(A2,OUTPUT);  //待命燈
  pinMode(sp,OUTPUT);  //蜂鳴器
  pinMode(A4,OUTPUT);
  pinMode(7,OUTPUT);   //馬達輸出1
  pinMode(8,OUTPUT);   //馬達輸出2
  pinMode(9,OUTPUT);   //馬達智能角
  pinMode(12,OUTPUT);  //夾取馬達1
  pinMode(13,OUTPUT);  //夾取馬達2
  DDRD = B11111111;    //0~6腳為七段

}

void loop() {
  sw1= digitalRead(A0);
  sw2= digitalRead(A1);
  analogWrite(9,150);
  if ( sw1 == HIGH){
      digitalWrite(ledd,HIGH);
      delay(100);
      digitalWrite(ledd,LOW);
      delay(100);
    digitalWrite(led,LOW);
    //馬達正反轉(含七段)
    //正轉
    if( sw2 == LOW){
      tone(sp,430);
      delay(500); 
      noTone(sp);
      PORTD = LEDs[1];
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      tt++;
      delay(1);
    } else {
      noTone(sp);
      tone(sp,500);
      delay(500);
      noTone(sp);
      tt=tt/2;
      PORTD = LEDs[0];
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      for (int i = 0 ; i <=4 ; i++){
        digitalWrite(12,HIGH);
        digitalWrite(13,LOW);
        delay(500);   
      } 
      PORTD = LEDs[2];
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      delay(tt);
      while(tt!=0){
        tone(sp,500);
        delay(500); 
        tone(sp,1000);
        delay(500);
        tt--;
        delay(1);
      }
      noTone(sp);
      PORTD = LEDs[0];
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      for (int i = 0 ; i <=4 ; i++){
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        delay(500);   
      }    
     }
  } else {
    noTone(sp);
    tt = 0;
    PORTD = LEDs[4];
    digitalWrite(led,HIGH);
  }
}
