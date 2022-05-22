#include<Servo.h>
#define trig 2 
#define echo 3 
#define led 4
#define ser 5
#define LDR A0
long duration; 
int distance; 
int ldrstatus;
Servo servo;
void setup() {
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(LDR, INPUT);
  servo.attach(ser);
  Serial.begin(9600);
}
void motion(){
   servo.write(0); 
   delay(1000); 
   servo.write(90); 
   delay(1000);
   servo.write(180); 
   delay(1000); 
  }
void human_there()
{ digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;  
  Serial.print(distance);
  if (distance < 20){
    digitalWrite(led,HIGH);
    }
   else{
    digitalWrite(led,LOW);
    } 
  }
void loop() {
  digitalWrite(led,LOW);
  ldrstatus = analogRead(LDR);
  if (ldrstatus <= 20){
    motion();
    human_there();
    }

}
