int Asw = 0;        //總開關變數
int sws = 0;        //開始開關變數
const int led=5;    //待機燈號(呼吸燈)
const int sw =A1;    //開始開關
const int bluepin=9;          
const int redpin=10;
const int greenpin=11;
const int buzzer = 0;
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
char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
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
void setup() {
    pinMode (A0,INPUT);  //總開關
    pinMode (sw,INPUT);  //開始開關
    pinMode (3,OUTPUT);  //馬達智能腳
    pinMode (1,OUTPUT);  //馬達輸出1
    pinMode (2,OUTPUT);  //馬達輸出2
    pinMode(led,OUTPUT); //待機LED燈
    pinMode(buzzer,OUTPUT);  //蜂鳴器
    noTone(buzzer);
}
void loop() {
   int bluevalue=0;
   int redvalue=0;
   int greenvalue=0;
   analogWrite(3,250);
    Asw = digitalRead(A0);
    sws = digitalRead(A1);
    if (Asw == HIGH){
    if (sws == HIGH){
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    delay(3000);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    int ii, length, toneNo;
    int duration;
    // star
    length = sizeof(starTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(starTone[ii]);
        duration = starBeat[ii]*333;
        tone(buzzer,toneTable[toneNo][3]);
        delay(duration);
        noTone(buzzer);
    }
    noTone(buzzer);
    delay(2000);
    } else {
    for(int i=1; i<=2; i=i+1){
    redvalue=random(1,30);
    greenvalue=random(1,20);
    bluevalue=random(1,50);
    analogWrite(redpin,redvalue);
    analogWrite(greenpin,greenvalue);
    analogWrite(bluepin,bluevalue);
    delay(500);
   }
    analogWrite(redpin,0);
    analogWrite(greenpin,0);
    analogWrite(bluepin,0);
    }
    } else {
      for(int fadeValue = 0;fadeValue <= 70; fadeValue = fadeValue + 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
  for(int fadeValue = 70;fadeValue >= 0; fadeValue = fadeValue - 5)
  {
    analogWrite(led,fadeValue);
    delay(100);
  }
    }

}
