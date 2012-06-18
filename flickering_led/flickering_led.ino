int led = 9;

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  analogWrite(led, 255);
  delay(50);
  analogWrite(led, 127);
  delay(50);
  analogWrite(led, 0);
  delay(50);
}
