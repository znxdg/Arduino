int tt = 0;            //前進時間初始值
int sw1 = 0;           //前端感測
int sp = 0;
int water = A0;
int WW = 0;
void setup() {
  pinMode(A1,INPUT);   //前端感測開關
  pinMode(sp,OUTPUT);
  pinMode (3,OUTPUT); //馬達智能腳
  pinMode (1,OUTPUT); //馬達輸出1
  pinMode (2,OUTPUT); //馬達輸出2
}

void loop() {
  noTone(sp);
 for(int i = 0 ; i <= 6;i++){
  spo();
  delay(1000);
 }
 tone(sp,1000);
 delay(500);
 tone(sp,800);
 delay(500);
 noTone(sp);
 tt = 0;
}
void spo(){
    analogWrite(3,150);
   sw1= digitalRead(A1);
   WW = analogRead(water);
   if ( WW >= 50){
    if(sw1 == LOW){
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    tt++;
    delay(1);
    } else {
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      noTone(sp);
    }
  } else {
    if(sw1 == HIGH){
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    delay(tt);
    } else {
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    }
  } 
}

