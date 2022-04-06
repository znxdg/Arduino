int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //清除開關變數
int sp = A1;     //蜂鳴器(得分音效)
int be = 0;
int st = 0;
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
//音樂
const int toneTable[7][5]={
    { 66, 131, 262, 523, 1046},  // C Do
    { 74, 147, 294, 587, 1175},  // D Re
    { 83, 165, 330, 659, 1318},  // E Mi
    { 88, 175, 349, 698, 1397},  // F Fa
    { 98, 196, 392, 784, 1568},  // G So
    {110, 220, 440, 880, 1760},  // A La
    {124, 247, 494, 988, 1976}   // B Si
};
char toneName[]="CDEFGAB";
char beeTone[]="GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";
char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
int beeBeat[]={
    1,1,2, 1,1,2, 1,1,1,1,1,1,2,
    1,1,2, 1,1,2, 1,1,1,1,4,
    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,
    1,1,2, 1,1,2, 1,1,1,1,4
};
int starBeat[]={
    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,
    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,
    1,1,1,1,1,1,2, 1,1,1,1,1,1,2
};
int getTone(char symbol) {
    int toneNo = 0;
    for ( int ii=0; ii<7; ii++ ) {
        if ( toneName[ii]==symbol ) {
            toneNo = ii;
            break;
        }
    }
    return toneNo;
}

int randNumber = 0;
void setup() {
  pinMode(sp,OUTPUT);
  pinMode(7,OUTPUT);  //紅
  pinMode(8,OUTPUT);  //綠
  pinMode(9,OUTPUT);  //藍
  pinMode(A0,INPUT);  //設定時間開關
  pinMode(A2,INPUT);  //清除開關
  pinMode(10,INPUT);  //小蜜蜂開關
  pinMode(11,INPUT);  //小星星開關
  DDRD = B11111111;
}

void loop() {
  randNumber = random(1, 4);
  a = digitalRead(A0);
  c = digitalRead(A2);
  be = digitalRead(10);
  st = digitalRead(11);
  PORTD = LEDs[b];
  if (be == HIGH){
    bee();
  } else {
    if (st == HIGH){
      star();
    } else {
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
  } else {
    ledd();
  }
  if(c == HIGH){
    b = 0;
  }
    }
  }
}
void ledd(){
  switch (randNumber) {
    case 1:
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    delay(6000);
    break;
    case 2:
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(6000);
    break;
    case 3:
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(6000);
    break;
  }
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(500);
}
void bee(){
  int ii, length, toneNo;
  int duration;
   length = sizeof(beeTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(beeTone[ii]);
        duration = beeBeat[ii]*333;
        tone(sp,toneTable[toneNo][3]);
        delay(duration);
        noTone(sp);
    }
    delay(2000);
}
void star(){
  int ii, length, toneNo;
  int duration;
  length = sizeof(starTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(starTone[ii]);
        duration = starBeat[ii]*333;
        tone(sp,toneTable[toneNo][3]);
        delay(duration);
        noTone(sp);
    }
    noTone(sp);
    delay(2000);
}

