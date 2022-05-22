#include <Servo.h>  //servo library
#define servo 3
Servo ser; 
void setup() {
  // put your setup code here, to run once:
  ser.attach(servo); // like pinMode();
}

void loop() {
  // put your main code here, to run repeatedly:
  ser.write(0); //go to 0 degree
  delay(1000); 
   // Make servo go to 90 degrees 
   ser.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
  
}
