int L = 0;          //左感測變數
int R = 0;          //右感測變數
int Asw = 0;        //總開關變數
int sw = 0;         //障礙物開關
int sp = 5;         //蜂鳴器(第5腳)
int x = 0;          //初始蜂鳴器叫一次變數
int y = 0;          //左轉蜂鳴器叫一次變數
int z = 0;          //右轉蜂鳴器叫一次變數
const int led=6;    //待機燈號
const int Led=7;    //左轉燈
const int Red=8;    //右轉燈
const int C = 300;  //左右轉比較值
const int l1 = A0;  //左光電晶體
const int l2 = A1;  //右光電晶體
void setup() {
  pinMode (A2,INPUT);  //障礙物開關
  pinMode (A3,OUTPUT); //警示LED
  pinMode (A4,INPUT);  //總開關
  pinMode (3,OUTPUT);  //智能腳
  pinMode (0,OUTPUT);  //左馬達1
  pinMode (1,OUTPUT);  //左馬達2
  pinMode (2,OUTPUT);  //右馬達1
  pinMode (4,OUTPUT);  //右馬達2
  pinMode(sp,OUTPUT);  //蜂鳴器(第5腳)
  pinMode(led,OUTPUT); //待機LED燈
  pinMode(Led,OUTPUT); //左轉燈
  pinMode(Red,OUTPUT); //右轉燈
}

void loop() {
    L = analogRead(l1);
    R = analogRead(l2);
    sw = digitalRead(A2);
    Asw = digitalRead(A4);
    analogWrite(3,100);
    if (Asw == HIGH){
    digitalWrite(led,LOW);
    if (sw == LOW){
    if ( L >= C & R >= C){                       //直線前進
    digitalWrite(Red,LOW);
    digitalWrite(Led,LOW);
    if ( x == 0){
       for (int a = 0; a<= 2; a++){
        tone(sp,500);
        delay(500); 
        tone(sp,1000);
        delay(500);
        digitalWrite(A3,HIGH);
        delay(100);
        digitalWrite(A3,LOW);
        delay(100);
    }
    noTone(sp);
    x++;
    }
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    delay(100);
    } else if ( L < C & R >= C){                //左轉
    digitalWrite(Led,HIGH);
    digitalWrite(Red,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    if ( z == 0){
       for (int a = 0; a<= 1; a++){
        tone(sp,262);
        delay(300); 
        tone(sp,294);
        delay(300);
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);
    }
    noTone(sp);
    z++;
    }
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    delay(500);  
    } else {                                    //右轉
    digitalWrite(Red,HIGH);
    digitalWrite(Led,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    if ( y == 0){
       for (int a = 0; a<= 1; a++){
        tone(sp,294);
        delay(300);
        tone(sp,262);
        delay(300);
        digitalWrite(A3,HIGH);
        delay(50);
        digitalWrite(A3,LOW);
        delay(50);
    }
    noTone(sp);
    y++;
    }
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    delay(500);
    } 
    } else {                                    //撞到障礙物停止
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    for (int a = 0; a<= 3; a++){
        tone(sp,500);
        delay(500); 
        digitalWrite(A3,HIGH);
        delay(100);
        digitalWrite(A3,LOW);
        delay(100);
    }
    noTone(sp);
    }
    } else {
      digitalWrite(0,LOW);
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(led,HIGH);
      digitalWrite(Led,LOW);
      digitalWrite(Red,LOW);
      x = 0;
      y = 0;
      z = 0;
    }
    
    
}
