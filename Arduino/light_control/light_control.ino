int sensorPin = 0;
int sensorVal = 0;
void setup() { 
  Serial.begin(9600);
 pinMode(10,OUTPUT);
 pinMode(A0,INPUT);
}
void loop() {
 sensorVal = analogRead(sensorPin); 
 Serial.println(sensorVal);
 sensorVal = map(sensorVal, 0, 1023, 0, 255);
 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvanalogWrite(10,sensorVal);
}
