/*

 Mary Had a Little Lamb
 
 circuit:
 * 8-ohm speaker on digital pin 13
 
 created 21 Jan 2010
 modified 30 Aug 2011
 made awesome 14 May 2012
 by Tom Igoe and Brad Osgood 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */

 #include "pitches.h"
 #define SONG_LENGTH 24

 #define SPEAKER_PIN 9

// notes in the melody:
  
int melody1[] = {
  NOTE_A3, NOTE_G3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_C3, NOTE_C3,
  NOTE_A3, NOTE_G3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_F3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,4,4,
  4,4,4,4,4,4,
  4,4,4,4,4,4,
  4,4,4,4,4,4
};

void setup() {
}

void loop() {
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < SONG_LENGTH; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SPEAKER_PIN, melody1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(SPEAKER_PIN);
  }
}