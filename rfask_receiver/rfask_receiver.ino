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

#define LED_PIN 13

void setup() {
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // Debugging only
  Serial.println("setup");

  // Initialise the IO and ISR
  vw_set_rx_pin(3);
  vw_setup(2000);   // Bits per sec
  vw_rx_start();    // Start the receiver PLL running
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) { // Non-blocking
    digitalWrite(LED_PIN, HIGH); // Flash a light to show received good message

    // Message with a good checksum received, dump it.
    Serial.print("Got: ");
    char* charBuf = (char*)buf;
    Serial.print(charBuf);
    Serial.println("");
  
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
}
