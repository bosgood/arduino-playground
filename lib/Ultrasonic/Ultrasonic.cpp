/*
  Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Ranging Module.library

  Created by ITead studio. Apr 20, 2010.
  Enhanced by Brad Osgood, Jun 5, 2012.
  iteadstudio.com
  bosgood.com
*/

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
   _triggerPin = triggerPin;
   _echoPin = echoPin;
}

unsigned long Ultrasonic::Timing() {
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_triggerPin, LOW);
  return pulseIn(_echoPin, HIGH);
}

unsigned long Ultrasonic::Ranging(int sys) {
  long duration = Timing();
  return (sys) ? duration / 29 / 2 :
                 duration / 74 / 2;
}