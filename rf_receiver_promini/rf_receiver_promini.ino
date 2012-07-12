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

#define RX_PIN 9
#define BUZZ_PIN 10
#define LED_PIN 13

void setup() {
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  Serial.begin(9600); // Debugging only
  Serial.println("setup");

  // Initialise the IO and ISR
  vw_set_rx_pin(RX_PIN);
  vw_setup(2000);   // Bits per sec
  vw_rx_start();    // Start the receiver PLL running
}

void effectOff() {
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZ_PIN);
  // digitalWrite(BUZZ_PIN, LOW);
}

void effectOn() {
  digitalWrite(LED_PIN, HIGH); // Flash a light to show received good message
  tone(BUZZ_PIN, 33, 4);
  // digitalWrite(BUZZ_PIN, HIGH);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) { // Non-blocking
    effectOn();

    // Message with a good checksum received, dump it.
    Serial.print("Got: ");
    char* charBuf = (char*)buf;

    // Remove last character of message to clean it up
    int len = strlen(charBuf);
    for (int i = 0; i < len - 1; i++) {
      Serial.print(charBuf[i]);
    }
    Serial.println("");
    delay(200);
    effectOff();
  }
}
