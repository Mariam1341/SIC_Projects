//unsigned force the user to input a positive number
#define led_1 5
#define led_2 3
#define led_3 2
#define led_4 9
#define led_5 8
#define led_6 6
#define led_7 11 
#define led_8 12 
#define led_9 13
void setup() {
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);
  pinMode(led_9, OUTPUT); 
}
void leds(int num){
  if (num == 0 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9){
    digitalWrite(led_1,HIGH);
    }
  if (num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9){
    digitalWrite(led_2,HIGH);
    }
  if (num == 0 || num == 1 ||num == 2 || num == 3 ||num == 4 || num == 7 || num == 8 || num == 9){
    digitalWrite(led_3,HIGH);
    }
  if (num == 0 || num == 2 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9){
    digitalWrite(led_4,HIGH);
    }
  if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9){
    digitalWrite(led_5,HIGH);
    }
  if (num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9){
    digitalWrite(led_6,HIGH);
    } 
  if (num == 0 || num == 2 || num == 3 || num == 6 || num == 7 || num == 8){
    digitalWrite(led_7,HIGH);
    }   
  if (num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9){
    digitalWrite(led_8,HIGH);
    }      
  if (num == 0 || num == 1 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9){
    digitalWrite(led_9,HIGH);
    }   
  delay(6000);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);  
  digitalWrite(led_3, LOW);  
  digitalWrite(led_4, LOW);  
  digitalWrite(led_5, LOW);  
  digitalWrite(led_6, LOW);  
  digitalWrite(led_7, LOW);  
  digitalWrite(led_8, LOW);  
  digitalWrite(led_9, LOW);  
          
  }
void loop() {
  // put your main code here, to run repeatedly:


  
  for (int i = 0;i < 10;i++){
    leds(i);
    }

}
