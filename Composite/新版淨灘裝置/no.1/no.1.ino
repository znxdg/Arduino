int i;           //近接開關變數
int ia = 0;          //分辨開口位置
int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int sp = A1;     //蜂鳴器(得分音效)
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
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode(10,OUTPUT); 
  pinMode(A2,INPUT);
  pinMode(sp,OUTPUT);
  digitalWrite(10,LOW);
  DDRD = B11111111;
}

void loop() {
  analogWrite(9,250);
  i = digitalRead(A2);
  if(i == 0){
    ia++;
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(1000);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,HIGH);
  } else {
    if(ia == 1){
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      ia = 0;
      digitalWrite(10,LOW);
    }
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
  }
  PORTD = LEDs[b];
  a = digitalRead(A0);
  if (a == HIGH){
    b++;
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
}
