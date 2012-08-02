/*
   Beep Beep

    Makes a beeping noise twice.
*/

#define SPEAKER_PIN 9
#define NOTE_LENGTH 80
#define FREQ 2960

void setup() {
    beep();
    beep();
}

void beep() {
    tone(SPEAKER_PIN, FREQ, NOTE_LENGTH);
    delay(NOTE_LENGTH);
    noTone(SPEAKER_PIN);
    delay(NOTE_LENGTH);
}

void loop() {
    // nothing to do here
}
