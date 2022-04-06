int a = 0;       //設定時間開關
int b = 0;       //七段顯示(設定變數)
int c = 0;       //七段顯示(倒數變數)
int sw = 0;      //倒數開關
int clean = 0;   //清除開關
int wetVal =0;
const int lowAlertVal = 200;
const int buzzerPin = 10;
const int analogIn = A5;
const int variable = A4;
const int bluepin=11;
const int greenpin=12;
const int redpin=13;
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
const int buzzer =A3;
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
   pinMode(A0,INPUT);  //設定時間開關
   pinMode(A1,INPUT);  //開始倒數開關
   pinMode(A2,INPUT);  //清除開關
   pinMode(buzzerPin,OUTPUT);
   pinMode (7,OUTPUT); //馬達輸出1
   pinMode (8,OUTPUT); //馬達輸出2
   pinMode (9,OUTPUT); //馬達智能腳
   DDRD = B11111111;
   pinMode(buzzer,OUTPUT); //音樂設定
   noTone(buzzer);
}

void loop() {  
  wetVal = analogRead(analogIn);
  if( wetVal > lowAlertVal){
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
  int bluevalue=0;
  int greenvalue=0;
  a = digitalRead(A0);
  sw = digitalRead(A1);
  clean = digitalRead(A2);
  PORTD = LEDs[b];
  if (a == HIGH){
    b++;
    PORTD = LEDs[b];
    delay(500);
    c = b;
    if ( b > 9){
      b = 0;
    }
  } 
  if (sw == HIGH){
      //
    int ii, length, toneNo;
    int duration;
    length = sizeof(starTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(starTone[ii]);
        duration = starBeat[ii]*333;
        tone(buzzer,toneTable[toneNo][3]);
        delay(duration);
        noTone(buzzer);        
    }
    noTone(buzzer);
    delay(100);
    // 
    for(;b>=0;b--){
    int sensorValue = analogRead(variable);
    analogWrite(9,sensorValue / 4);
    if( wetVal > lowAlertVal){
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
    PORTD = LEDs[b];
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(redpin,1);
        delay(100);
        digitalWrite(redpin,0);
        delay(100);
        digitalWrite(greenpin,1);
        delay(100); 
        digitalWrite(greenpin,0);
        delay(100);
        digitalWrite(bluepin,1);               
        delay(100);
        digitalWrite(bluepin,0); 
        delay(100);
        }
    if(b<0){
      b = c;
    }
    }
  if(clean == HIGH){
    b = 0;
    c = 0;
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  }     
