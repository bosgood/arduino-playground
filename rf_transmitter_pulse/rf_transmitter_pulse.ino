#define LED_PIN 13

void lightLed() {
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(1200);
}

void loop() {
  Serial.write("test!");
  lightLed();
  delay(2000);
}
