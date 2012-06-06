/**
 * rangefinder_cpp - Sketch to read a value from an ultrasound sensor and display the value
 * on an LCD
 * 
 * Author: Brad Osgood - http://github.com/bosgood / http://bosgood.com
 * Date: Jun 5 2012
 *
 * Thanks to ITead studio for the original Ultrasonic.cpp and hardware and
 * Joe Schlesinger (http://arcbotics.com) for inspiration
 */

#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#include <string.h>
#include <stdlib.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Ultrasonic sonic = Ultrasonic(A1, A0);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.write("sensor proximity:");
}

void loop() {
    // Calculate range from sensor
    long cm = sonic.Ranging(CENTIMETERS);

    // Print to display
    lcd.setCursor(0, 1);
    lcd.write("  ");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    lcd.setCursor(3, 1);
    lcd.write("cm");

    delay(100);
}
