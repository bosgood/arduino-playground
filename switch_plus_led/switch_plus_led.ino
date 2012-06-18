int ledPin = 13;      // LED is connected to digital pin 11
int switchPin = 7;    // switch connected to digital pin 7
int switchValue;      // a variable to keep track of when switch is pressed
       
void setup() {      
   pinMode(ledPin, OUTPUT);     // sets the ledPin to be an output
   pinMode(switchPin, INPUT);     // sets the switchPin to be an input
   digitalWrite(switchPin, HIGH);     // sets the default (unpressed) state of switchPin to HIGH
}      
       
void loop() {      
  switchValue = digitalRead(switchPin);     // check to see if the switch is pressed
  if (switchValue == LOW) {     // if the switch is pressed then,
    digitalWrite(ledPin, HIGH);     // turn the LED on
  } else {
    digitalWrite(ledPin, LOW);     // turn the LED off
  }      
}       
