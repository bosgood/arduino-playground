#define IN_PIN 9

void setup() {
    pinMode(IN_PIN, OUTPUT);
    Serial.begin(9600);
}


void loop() {
    int inVal = analogRead(IN_PIN);
    Serial.println(inVal);
    delay(50);
}