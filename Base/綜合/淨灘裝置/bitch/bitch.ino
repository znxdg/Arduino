int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //七段顯示(倒數變數)
int sw = 0;      //總開關
int sp = A1;     //蜂鳴器(得分音效)
const int led = 9;
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
    for(int fadeValue = 0;fadeValue <= 70; fadeValue = fadeValue + 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
    tone(sp,500);
    delay(500); 
    tone(sp,1000);
    delay(500);
    noTone(sp);
    for(int fadeValue = 70;fadeValue >= 0; fadeValue = fadeValue - 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
    delay(500);
  }  
  }   
