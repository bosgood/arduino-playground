/*
  Ultrasonic.h - Library for HR-SC04 Ultrasonic Ranging Module.
  
  Created by ITead studio. Alex, Apr 20, 2010.
  Enhanced by Brad Osgood, Jun 5, 2012.
  iteadstudio.com
  bosgood.com
*/

#ifndef Ultrasonic_h
#define Ultrasonic_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "WConstants.h"
#endif

#define CENTIMETERS 1
#define INCHES 0

/**
 * Defines an interface for the HR-SC04 module
 */
class Ultrasonic
{
  public:
    // Ultrasonic();
    /**
     * Constructs an Ultrasonic ranger
     * @param TP trigger pin number
     * @param EP echo pin number
     */
    Ultrasonic(int triggerPin, int echoPin);
    /**
     * Causes an ultrasonic pulse to be sent out
     * @return the duration between pulse send and return (ms)
     */
    unsigned long Timing();
    /**
     * Gets the range of the object in front of the sensor
     * @param sys controls type of measurement returned, truthy for centimeters,
     * falsy for inches
     * @return the distance of the object from the sensor
     */
    unsigned long Ranging(int sys);

  private:
    int _triggerPin;
    int _echoPin;
};

#endif