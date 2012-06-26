#define PUSH_BUTTON 9
#define LED_PIN 13

void setup() {
  pinMode(PUSH_BUTTON, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(PUSH_BUTTON);
  digitalWrite(LED_PIN, buttonState);
}
