#define POT_PIN A0

int val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(POT_PIN);
  Serial.println(val);
  delay(100);
}