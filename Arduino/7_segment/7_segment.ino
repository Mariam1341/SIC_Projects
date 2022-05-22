int seg[7];
void setup() {
  // put your setup code here, to run once:
  for (int i = 8; i >=2; i--)
  {
    seg[8-i] = i;
    pinMode(i, OUTPUT);
  } 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 8; i >=2; i--)
  {
    seg[8-i] = i;
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    
  } 
  
}
