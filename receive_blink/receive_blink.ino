/**
 * Receives messages over the serial interface for blinking an LED on and off.
 * 
 * Author: Brad Osgood
 * Date: Jun 6 2012
 */
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
 
void loop(){
  if (Serial.available()){
 
    byte val = Serial.read();
 
    if (val == 'x') { digitalWrite(13, HIGH); }
    if (val == 'o') { digitalWrite(13, LOW); }
  }
}
