int sp = 11;
const int led=A1;
int a=0;
const int b=600;
int sw = 0;
const int redpin=7;
const int bluepin=8;
const int greenpin=10;          
byte index = 9;
const byte LEDs[7] = {
  B1111110,
  B0110000,
  B1101101,
  B1111001,
  B0110011,
  B1011011,
  B1011111
};
void setup() {
  pinMode(sp,OUTPUT);
  pinMode(led,OUTPUT);   //光控
  pinMode (7,OUTPUT);    //紅燈
  pinMode (8,OUTPUT);    //藍燈
  pinMode (9,OUTPUT);    //馬達智能
  pinMode (10,OUTPUT);   //綠燈
  pinMode(11,OUTPUT);     //停止開關
  pinMode (12,OUTPUT);   //馬達輸出1
  pinMode (13,OUTPUT);   //馬達輸出2
  DDRD = B11111111;
}
void loop() {
  analogWrite(9,150);  
  sw = digitalRead(11);
 for(int i = 6; i>=0 ; i--){
   PORTD = LEDs[i];
   delay(1000);
 }
  analogWrite(redpin,150);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW); 
  delay(650);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(3000);
    analogWrite(redpin,0);

  analogWrite(greenpin,150);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW); 
  delay(650);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(3000);
  analogWrite(greenpin,0);

  for(int i = 6; i>=0 ; i--){
   PORTD = LEDs[i];
   delay(1000);
 }
  digitalWrite(led,HIGH);
  analogWrite(bluepin,150);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW); 
  delay(650);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(3000);
  analogWrite(bluepin,0);
    digitalWrite(led,LOW);
  
}
