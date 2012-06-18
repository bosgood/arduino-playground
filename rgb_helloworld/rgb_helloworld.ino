int redPin = 10;
int bluePin = 9;
int greenPin = 8;

void setup() {                
  pinMode(redPin, OUTPUT);     
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

}

void loop() {

  analogWrite(redPin, 255);
  analogWrite(bluePin, 0);
  analogWrite(greenPin, 0);

  // analogWrite(redPin, 0);
  // analogWrite(bluePin, 0);

  // for (int i = 0; i < 255; i++) {
  //   analogWrite(greenPin, i);
  // }

  delay(100);
}
