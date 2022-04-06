int sw = 0;    //前進開關變數
int sw1 = 0;   //後退開關變數
int sw2 = 0;   //音樂開關變數
int buzzer = A5;     //蜂鳴器
const byte LED[] = {A1,A2,A3,A4}; //霹靂燈
const byte total = sizeof(LED);
const byte LEDs[3] = {B1111110,B0110000,B1101101};
//青花瓷
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
  //
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
    tone(A5, melody[note], noteDuration);
    delay(noteDuration * 1.30);
  }
}

void setup() {
  pinMode(7,INPUT);   //前進開關
  pinMode(8,INPUT);   //後退開關
  pinMode(A0,INPUT);  //音樂開關
  pinMode(buzzer,OUTPUT);  //蜂鳴器
  pinMode(9,OUTPUT);   //馬達智能腳
  pinMode(10,OUTPUT);  //旋轉馬達輸出1
  pinMode(11,OUTPUT);  //旋轉馬達輸出2
  pinMode(12,OUTPUT);  //行動馬達輸出1
  pinMode(13,OUTPUT);  //行動馬達輸出2
  DDRD = B11111111;    //0~6腳為七段
  for (byte i=0 ; i < total ;i++){
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  analogWrite(9,250);
  sw = digitalRead(7);
  sw1 = digitalRead(8);
  sw2 = digitalRead(A0);
  if (sw2 == HIGH){
  play(melody, noteDurations, sizeof(melody) / sizeof(int));
  delay(2000);
} else {
  if (sw == HIGH){
    if(sw1 == HIGH){
     PORTD = LEDs[2];
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
     delay(3000);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
     PORTD = LEDs[0];
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(6000);
    } else {
    PORTD = LEDs[1];
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(3000);
    PORTD = LEDs[0];
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    for (int i = 0 ; i<= 3;i++){
      tone(buzzer,500);
      delay(500); 
      tone(buzzer,1000);
      delay(500);
    }
    noTone(buzzer);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(3000);
    }
  } else {
    PORTD = LEDs[0];
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(1);
  }
}
}
