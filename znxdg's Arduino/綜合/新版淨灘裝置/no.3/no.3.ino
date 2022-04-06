int i;           //近接開關變數
int ia = 0;      //分辨開口位置
int stp1 = 0;     //停止1
int t = 0;     //停止2
int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int aa = 0;      //音樂1
int bb = 0;      //音樂2
int sp = A1;     //蜂鳴器(得分音效)
int mc = 0;      //音樂開關讀取質
int clean = 0;   //清除變數
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
#define NTC0 -1
#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495

#define NTCL1 131
#define NTCL2 147
#define NTCL3 165
#define NTCL4 175
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248  

#define NTCH1 525
#define NTCH2 589
#define NTCH3 661
#define NTCH4 700
#define NTCH5 786
#define NTCH6 882
#define NTCH7 990
//列出全部C调的频率
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
#define NOTE_    0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
//列出所有节拍
int tune[]=                 //根据简谱列出各频率
{
  NTC5,NTC5,NTC6,
  NTCH1,NTC6,NTC5,NTC6,NTCH1,NTC6,NTC5,
  NTC3,NTC3,NTC3,NTC5,
  NTC6,NTC6,NTC5,NTCH3,NTCH3,NTCH2,NTCH1,
  NTCH2,NTCH1,NTCH2,
  NTCH3,NTCH3,NTCH2,NTCH3,NTCH2,NTCH1,NTCH2,NTCH1,NTC6,

  NTCH2,NTCH2,NTCH2,NTCH1,NTC6,NTC5,
  NTC6,NTC5,NTC5,NTCH1,NTC6,NTC5,NTC1,NTC3,
  NTC2,NTC1,NTC2,
  NTC3,NTC5,NTC5,NTC3,NTCH1,NTC7,
  NTC6,NTC5,NTC6,NTCH1,NTCH2,NTCH3,

  NTCH3,NTCH2,NTCH1,NTC5,NTCH1,NTCH2,NTCH3,

  NTCH2,NTC0,NTCH3,NTCH2,
  NTCH1,NTC0,NTCH2,NTCH1,NTC6,NTC0,

  NTCH2,NTC6,NTCH1,NTCH1,NTCH1,NTC6,NTC5,NTC3,
  NTC5,
  NTC5,NTC6,NTCH1,NTC7,NTC6,
  NTCH3,NTCH3,NTCH3,NTCH3,NTCH2,NTCH2,NTCH1,
  NTC6,NTCH3,NTCH2,NTCH1,NTCH2,NTCH1,NTC6,
  NTCH1,
};
float durt[]=                   //根据简谱列出各节拍
{
0.5,0.25,0.25,
1.5,0.5,0.5,0.25,0.25,0.5,0.5,
1+1+1,0.5,0.25,0.25,
1.5,0.5,0.5,0.5,0.25,0.25,0.5,
1+1+1,0.5,0.5,
0.5,0.5,0.5,0.25,0.25,0.5,0.25,0.25,0.5,
0.5,0.5,0.5,0.25,0.25,1+1,
0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
1+1+1,0.5,0.5,


1.5,0.5,0.5,0.5,0.5,0.5,
1.5,0.5,1,0.5,0.25,0.25,
1.5,0.5,0.5,0.5,0.5,0.25,0.25,
1+1+1,0.5,0.25,0.25,
1,0.5,0.25,0.25,1,1,
0.5,0.5,0.5,0.5,1,0.25,0.25,0.5,
1+1+1+1,
0.5,0.5,0.5,0.5,1+1,
0.5,0.5,0.5,0.5,1.5,0.25,0.25,
1.5,0.5,1,0.25,0.25,0.25,0.25,1+1+1+1,

};
int length;
int melody[] = {
  NOTE_, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_,
  NOTE_, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_G3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_,
  NOTE_, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_,
  
  NOTE_, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_,
  NOTE_, NOTE_G3, NOTE_A3, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_C4, NOTE_A3, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_,
  //
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_,
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_,
  NOTE_, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_,
  
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_,
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,
  NOTE_G3, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_,
};

int noteDurations[] = {
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 
  16, 8, 16, 16, 16, 4, 8, 
};
void play(int *melody, int *noteDurations, int num){
  for(int note = 0; note < num; note++){
    int noteDuration = 3000 / noteDurations[note];
    tone(sp, melody[note], noteDuration);
    delay(noteDuration * 1.30);
  }
}

void setup() {
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode(11,INPUT);
  pinMode(A0,INPUT);
  pinMode(sp,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  length=sizeof(tune)/sizeof(tune[0]);   //计算长度
  DDRD = B11111111;
}

void loop() {
  analogWrite(9,250);
  i = digitalRead(A2);
  mc = digitalRead(A3);
  stp1 = digitalRead(11);
  music();
  if(i == 0){
    if(stp1 == 0){
    ia++;
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(1);
    t++;
    } else {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(15000);
    }
  } else {
    if(ia > 0 ){ 
        digitalWrite(7,LOW);
        digitalWrite(8,HIGH);
        delay(t);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(10);
      ia = 0;
      t = 0;
    } 
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(1000);
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
  clean = digitalRead(A3);
  if (clean == HIGH){
    b = 0;
  }
}
void music(){
   aa = digitalRead(A4);
   bb = digitalRead(A5);
  if(aa == HIGH){
    for(int x=0;x<length;x++)
  {
    tone(sp,tune[x]);
    delay(500*durt[x]);   //这里用来根据节拍调节延时，500这个指数可以自己调整，在该音乐中，我发现用500比较合适。
    noTone(sp);
  }
  delay(2000);
  }
  if(bb == HIGH){
    play(melody, noteDurations, sizeof(melody) / sizeof(int)); 
  delay(2000);
  }
}
