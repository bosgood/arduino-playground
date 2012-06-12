#define LED_PIN 13
#define POT_PIN A0

int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0); // read between 0-1023 (10 bits)
  Serial.println(sensorValue);

  if (sensorValue < 61) {
    digitalWrite(LED_PIN, LOW);
  }

  if (sensorValue >= 61) {
    digitalWrite(LED_PIN, HIGH);
  }

  delay(10);
}