#include <LiquidCrystal.h>
#define MOTOR1 8
#define MOTOR2 9
#define EN 10
#define POT A0
#define buzzer 7
int POT_VAL;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EN,OUTPUT);
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2);
}
 
void loop() {
  tone(buzzer, 1000); 
  delay(1000);
  analogWrite(EN,130);
  digitalWrite(MOTOR1,HIGH);
  digitalWrite(MOTOR2,LOW);
  if(MOTOR1 == 1){
    lcd.print("Hello, Enter");  
    }else{
      lcd.print("NO Visitors");  
      }
   
}
