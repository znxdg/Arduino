int a = 0;          //投錢數初始值
int b = 0;          //延遲動作
int c = 0;          //光敏電阻初始值
int sw1 = 0;        //開關初始值
const int cds = A0;  //光敏電阻偵測腳
const byte LEDs[10] = {B1111110,B0110000,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,
  B1111111,B1111011};
void setup() {
  pinMode (7,INPUT);    //投錢數開關
  pinMode (8,OUTPUT);   //底座&手臂馬達輸出1
  pinMode (9,OUTPUT);   //底座&手臂馬達智能
  pinMode (10,OUTPUT);  //做動(頭)馬達智能
  pinMode (11,OUTPUT);  //底座&手臂馬達輸出2
  pinMode (12,OUTPUT);  //做動(頭)馬達輸出1
  pinMode (13,OUTPUT);  //做動(頭)馬達輸出2
  DDRD = B11111111;     //七段輸出腳:0~6
}

void loop() {
  PORTD = LEDs[a];
  c = analogRead(cds);  //讀取光敏電阻值
  sw1 = digitalRead(7); //讀取投錢數
  analogWrite(9,100);   //設定底座馬達智能腳
  analogWrite(10,c/4);
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
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
    if(a % 2 == 0){
      digitalWrite(8,HIGH);
      digitalWrite(11,LOW);
      delay(30000);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);
    } else{
      digitalWrite(8,LOW);
      digitalWrite(11,HIGH);
      delay(30000);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);
    }
      b=0;
    } else {
    digitalWrite(8,LOW);
    digitalWrite(11,LOW);
    }
  }

}
