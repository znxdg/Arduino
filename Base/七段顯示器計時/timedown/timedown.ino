int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //七段顯示(倒數變數)
int sw = 0;      //總開關
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
   pinMode(7,INPUT);
   pinMode(8,INPUT);
   DDRD = B11111111;
}

void loop() {
  a = digitalRead(7);
  sw = digitalRead(8);
  PORTD = LEDs[b];
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
    for(;b>0;b--){
    PORTD = LEDs[b];
    delay(500);
    if(b==0){
       b = 0;
    }
    }
    }
  }    
