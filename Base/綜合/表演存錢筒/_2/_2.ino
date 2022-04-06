int a = 0;          //投錢數初始值
int b = 0;          //延遲動作
int c = 0;          //光敏電阻初始值
int sw1 = 0;        //開關初始值
const int cds = A0;  //光敏電阻偵測腳
const byte LEDs[10] = {B1111110,B0110000,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,
  B1111111,B1111011};
  const int buzzer = A1;
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
void setup() {
  pinMode (7,INPUT);    //投錢數開關
  pinMode (8,OUTPUT);   //底座&手臂馬達輸出1
  pinMode (9,OUTPUT);   //底座&手臂馬達智能
  pinMode (10,OUTPUT);  //做動(頭)馬達智能
  pinMode (11,OUTPUT);  //底座&手臂馬達輸出2
  pinMode (12,OUTPUT);  //做動(頭)馬達輸出1
  pinMode (13,OUTPUT);  //做動(頭)馬達輸出2
  DDRD = B11111111;     //七段輸出腳:0~6
  pinMode(buzzer,OUTPUT);

    noTone(buzzer);

}

void loop() {
  PORTD = LEDs[a];
  c = analogRead(cds);  //讀取光敏電阻值
  sw1 = digitalRead(7); //讀取投錢數
  analogWrite(9,100);   //設定底座馬達智能腳
  analogWrite(10,c/5);
  if (sw1 == HIGH) { 
    a++;
    b++;
    if(a > 9 ){
      a=0;
    }
  } 
    PORTD = LEDs[a];
    delay(800);  
  if (sw1 == LOW){
  if ( b > 0 ){
    if(a % 2 == 0){
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(11,LOW);
    int ii, length, toneNo;
    int duration;
    // bee
    length = sizeof(beeTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(beeTone[ii]);
        duration = beeBeat[ii]*333;
        tone(buzzer,toneTable[toneNo][3]);
        delay(duration);
        noTone(buzzer);
    }
      delay(30000);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    } else{
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    digitalWrite(11,HIGH);
    int ii, length, toneNo;
    int duration;
    // star
    length = sizeof(starTone)-1;
    for ( ii=0; ii<length; ii++ ) {
      toneNo = getTone(starTone[ii]);
      duration = starBeat[ii]*333;
      tone(buzzer,toneTable[toneNo][3]);
      detion);
      noTone(buzzer);
      }
      noTone(buzzer);
      delay(30000);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
      b=0;
    } else {
    digitalWrite(8,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    }
  }
}
