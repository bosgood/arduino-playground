#include <LiquidCrystal.h>
#include <string.h>
#include <stdlib.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int echoPin = A0;
int trigPin = A1;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.write("sensor proximity:");

    int duration, cm;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    cm = duration / 29 / 2;

    // Serial.print(cm);
    // Serial.println(" cm");

    lcd.setCursor(0, 1);
    lcd.write("  ");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    lcd.setCursor(3, 1);
    lcd.write("cm");
}
