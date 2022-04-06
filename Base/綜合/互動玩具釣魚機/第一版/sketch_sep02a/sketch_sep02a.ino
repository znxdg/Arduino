int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //清除開關變數
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
int randNumber = 0;
void setup() {
  pinMode(sp,OUTPUT);
  pinMode(7,OUTPUT);  //紅
  pinMode(8,OUTPUT);  //綠
  pinMode(9,OUTPUT);  //藍
  pinMode(A0,INPUT);  //設定時間開關
  pinMode(A2,INPUT);  //清除開關
  DDRD = B11111111;
}

void loop() {
  randNumber = random(1, 4);
  a = digitalRead(A0);
  c = digitalRead(A2);
  PORTD = LEDs[b];
  switch (randNumber) {
    case 1:
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    sw();
    delay(6000);
    break;
    case 2:
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    sw();
    delay(6000);
    break;
    case 3:
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    sw();
    delay(6000);
    break;
  }
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(500);
}
void sw(){
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
  if(c == HIGH){
    b = 0;
  }
}

