int sw1 = 0;           //開始行動開關變數
int sp = A1;           //蜂鳴器
int sensorValue = 0;
byte index = 0 ;
const byte LED[] = {A3,A4,A5,12,13};  //霹靂燈
const byte total = sizeof(LED);       //燈數量
const byte LEDs[4] = {B1111110,B0110000,B1101101,B0000000};
void setup() {
  pinMode(7,OUTPUT);   //移動馬達輸出1
  pinMode(8,OUTPUT);   //移動馬達輸出2
  pinMode(9,OUTPUT);   //馬達智能角
  pinMode(10,OUTPUT);  //夾取馬達1
  pinMode(11,OUTPUT);  //夾取馬達2
  pinMode(A0,INPUT);   //開始行動開關
  pinMode(sp,OUTPUT);  //蜂鳴器(A1)
  pinMode(A2,INPUT);   //可變電阻
  DDRD = B11111111;    //0~6腳為七段
  for (byte i=0 ; i < total ;i++){
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  noTone(sp);
  sw1 = digitalRead(A0);
  if(sw1 == HIGH){
    tone(sp,430);
    delay(500); 
    noTone(sp);
    PORTD = LEDs[1];
    int sensorValue = analogRead(A2);
    analogWrite(9,sensorValue/4);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(5000);
    tone(sp,500);
    delay(500); 
    noTone(sp);
    PORTD = LEDs[0];
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    for (int i = 0 ; i <=4 ; i++)
      {
        int sensorValue = analogRead(A2);
        analogWrite(9,sensorValue/4);
        digitalWrite(10,HIGH);
        digitalWrite(11,LOW);
        delay(500);   
      }
    tone(sp,500);
    delay(500);
    tone(sp,1000);
    delay(500);  
    noTone(sp);
    PORTD = LEDs[2];
    sensorValue = analogRead(A2);
    analogWrite(9,sensorValue/4);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(5000);
  } 
    noTone(sp);
    PORTD = LEDs[0];
    for(byte i=0;i<total;i++){
    digitalWrite(LED[i],LOW);
    }
    digitalWrite(LED[index],HIGH);
    index++;
    if (index == total){
    index = 0 ;
    }
    delay(100);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
}
