int sw1 = 0;           //開始行動開關變數
int sp = A1;           //蜂鳴器
int sensorValue = 0;
int sensorValue1 = 0;
byte index = 0 ;
const byte LED[] = {A4,A5,12,13};  //霹靂燈
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
  pinMode(A3,INPUT);   //方向
  DDRD = B11111111;    //0~6腳為七段
  for (byte i=0 ; i < total ;i++){
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  noTone(sp);
  sw1 = digitalRead(A0);
  if(sw1 == HIGH){    
    PORTD = LEDs[1];
    tone(sp,500);
    delay(500); 
    noTone(sp);
    for(int a = 0; a < 5;a++){
    sensorValue1 = analogRead(A3);
    sensorValue = analogRead(A2);
    analogWrite(9,sensorValue/4);
  if(sensorValue1 > 700){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(1000);
    } else if (sensorValue1 < 200){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(1000);
    } else{
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(1000);
    }
    }
    tone(sp,430);
    delay(500); 
    noTone(sp);
    PORTD = LEDs[0];
    for(int b = 0; b < 3;b++){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(1000);
    }
    tone(sp,500);
    delay(500);
    tone(sp,1000);
    delay(500);  
    noTone(sp);
    PORTD = LEDs[2];
    for(int c = 0; c < 5;c++){
    sensorValue = analogRead(A2);
    analogWrite(9,sensorValue/4);
    sensorValue1 = analogRead(A3);
  if(sensorValue1 > 700){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(1000);
    } else if (sensorValue1 < 200){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(1000);
    } else{
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(1000);
    }
    }
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
