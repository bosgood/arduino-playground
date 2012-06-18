#define LED_PIN 13

void lightLed() {
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(1200);
}

void loop() {
  if (Serial.available()) {
    Serial.read();

  }
}
