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
  pinMode(sp,OUTPUT);
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);  
  pinMode(A0,INPUT);
  DDRD = B11111111;
}

void loop() {
  a = digitalRead(A0);
  PORTD = LEDs[b];
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
