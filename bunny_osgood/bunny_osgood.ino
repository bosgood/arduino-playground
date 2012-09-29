/*

 Bunny Osgood

 A cute little friend.

 Aug 4 2012

*/

#define NOTE_LENGTH 100
#define FREQ 2960

#define PUSH_BUTTON 13
#define SPKR_PIN 12

void setup() {
  pinMode(PUSH_BUTTON, INPUT);
  // pinMode(SPKR_PIN, OUTPUT);

  beep();

  Serial.begin(9600);
  Serial.write("2");
}

void loop() {
  // Count 10 values in a row to make sure it's actually ON
  int allOn = 1;
  for (int i = 0; i < 25; i++) {
    int val = digitalRead(PUSH_BUTTON);
    if (!val) {
      Serial.print(val);
      allOn = 0;
      break;
    }
    delay(10);
  }

  // Serial.print(allOn);

  if (allOn) {
    beep();
    beep();
  }
  delay(50);
}

// Makes bunny beep
void beep() {
    tone(SPKR_PIN, FREQ, NOTE_LENGTH);
    delay(NOTE_LENGTH);
    noTone(SPKR_PIN);
    delay(NOTE_LENGTH);
}