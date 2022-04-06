int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //蓋子1變數
int d = 0;       //蓋子2變數
int e = 0;       //清除變數
int sw = 0;      //總開關
int sp = A1;     //蜂鳴器(得分音效)
int test = A2;   //光敏輸入
const byte LED[] = {A4,A5,12,13};
const byte total = sizeof(LED);
byte index = 0 ;
const byte LEDs[10] = {
  B1111110,
  B0110000,
  B1101101,
  B1111001,
  B0110011,
  B1011011,
  B1011111,
  B1110000,
  B1111111,
  B1111011
};
void setup() {
  pinMode(sp,OUTPUT);
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);  
  pinMode(A0,INPUT);
  pinMode(A3,INPUT);
  for (byte i=0 ; i < total ;i++){
    pinMode(LED[i],OUTPUT);
  }
  DDRD = B11111111;
}

void loop() {
  analogWrite(9,250);
  a = digitalRead(A0);
  e = digitalRead(A3);
  PORTD = LEDs[b];
  int Test = analogRead(test);
  if(c==0){
    if(Test > 100){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(3000);
    c=1;
    } 
  }
  if(d==0){
    if(Test <= 100){
    if(c > 0){
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      delay(3000);
      c = 0;
    } else {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    c=0;  
    }
  }
  }
  if (a == HIGH){
    b++;
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    if ( b >= 10){
      b = 0;
    }
    PORTD = LEDs[b];
    tone(sp,500);
    delay(500); 
    tone(sp,1000);
    delay(500);
    noTone(sp);
    delay(500);
    }
    if(e == HIGH){
      b = 0;
    }
    for(byte i=0;i<total;i++){
    digitalWrite(LEDs[i],LOW);
  }
   digitalWrite(LEDs[index],HIGH);
   index++;
  if (index == total){
  index = 0 ;
  }
  delay(100);
  }   
