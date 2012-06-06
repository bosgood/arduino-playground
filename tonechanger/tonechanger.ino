/*
  ToneChanger
  Reads a digital input on pin 2, alters the tone being played by the speaker
 
  by Brad Osgood
  Inspiration taken from DigitalReadSerial and Mary Had a Little Lamb.
*/

#include "pitches.h"
#define PUSH_BUTTON 2
#define SPEAKER 13

int note = NOTE_C3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(PUSH_BUTTON, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(PUSH_BUTTON);
  // print out the state of the button:

  tone(SPEAKER,
       (buttonState != 0) ? note++ : note,
       1000 / 8);

  delay(5);        // delay in between reads for stability
}
