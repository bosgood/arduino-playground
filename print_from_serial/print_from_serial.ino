#include <string.h>
#include <stdlib.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // int charCount = 0;
    delay(100);
    while (Serial.available()) {
      // charCount++;
      char c = Serial.read();
      Serial.print(c);
    }
    Serial.println();
  }
}