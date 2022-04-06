int temp = 0;           //溫度變數
int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //七段顯示(倒數變數)
int sw = 0;      //倒數開關
int clean = 0;   //清除開關
int sp = A5;     //蜂鳴器
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
  pinMode(A0,INPUT);    //溫度輸入腳
  pinMode(A1,OUTPUT);   //灑水LED
  pinMode(A2,INPUT);    //設定時間開關
  pinMode(A3,INPUT);    //開始倒數開關
  pinMode(A4,INPUT);    //清除開關
  pinMode(sp,OUTPUT);   //蜂鳴器
  DDRD = B11111111;
}

void loop() {
  a = digitalRead(A2);
  sw = digitalRead(A3);
  clean = digitalRead(A4);
  PORTD = LEDs[b];
  temp = analogRead(A0);
  if(temp > 300){
    digitalWrite(A1,HIGH);  
  } else {
    digitalWrite(A1,LOW);
  }
  if (a == HIGH){
    b++;
    PORTD = LEDs[b];
    delay(500);
    c = b;
    if ( b == 9){
      b = 0;
    }
  }  
  if (sw == HIGH){
    for(;b>=0;b--){
    PORTD = LEDs[b];
    delay(500);
     }
    if(b==0){
      for(int i = 0 ; i < 3 ; i++){
        tone(sp,500);
        delay(500); 
        tone(sp,1000);
        delay(500);
      }
      noTone(sp);
      delay(500);
    }
    if(b<0){
      b = c;
     }
   }
  if(clean == HIGH){
    b = 0;
  }
}
