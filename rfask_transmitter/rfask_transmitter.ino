// 
// SparkFun Electronics 2011
// NPoole
//
// RF ASK Transmitter/Reciever Example
//
// This code depends on the VirtualWire Library for Arduino and is
// based on the example code provided by Mike McCauley (mikem@open.com.au)
// See VirtualWire.h for detailed API docs. 
//
// This example shows how to use the VirtualWire library to send and receive
// simple messages and use them to control digital I/O pins. Buttons are 
// connected to the transmitting Arduino on pins 8-11 (to ground, internal 20k
// pull-up resistors are set in the code) and in the same fashion,
// LEDs are connected to the recieving Arduino on pins 8-11. When a button is
// pressed on the transmitter, the corresponding LED will light on the reciever.
// This document contains both transmitter and reciever code, simply de-comment 
// the piece of code you need to use.

#include <VirtualWire.h>

#define BUTTON_PIN 7
#define LED_PIN 13

char buf[VW_MAX_MESSAGE_LEN];

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);	  // Debugging only
  Serial.println("setup");

  // Initialise the IO and ISR
  vw_set_tx_pin(2); 
  vw_setup(2000);	    // Bits per sec
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    const char *msg = "hello precious";
    digitalWrite(LED_PIN, HIGH);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(LED_PIN, LOW);
    delay(500); // Refuse to send messages too quickly
  }

  // if (Serial.available()) {
  //   delay(200); // Wait for entire message to arrive
  //   buf[0] = '\0'; // Erase the buffer string

  //   // Read all the data from the serial port into the buffer 
  //   int i = 0;
  //   while (Serial.available()) {
  //     buf[i] = Serial.read();
  //   }

  //   // Serial.println(buf);
    
  //   // Send the message over RF
  //   digitalWrite(LED_PIN, HIGH);
  //   vw_send((uint8_t *)buf, strlen(buf));
  //   vw_wait_tx(); // Wait until the whole message is gone
  //   digitalWrite(LED_PIN, LOW);
  // }
}
