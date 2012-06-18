// RGB LED - Automatic Color Cycling
//
// Matthew L Beckler 
// matthew at mbeckler dot org

int redPin = 10;
int bluePin = 9;
int greenPin = 8;

int redVal;
int greenVal;
int blueVal;

void setup()
{
  redVal = 255;
  greenVal = 255;
  blueVal = 255;
  update();
}

// This function updates the LED outputs.
void update()
{
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}

// This function updates one of the color variables
// either getting brighter or getting dimmer.
// It also updates the outputs and delays for 10 milliseconds.
void color_morph(int* value, int get_brighter)
{
  for (int i = 0; i < 255; i++)
  {
    if (get_brighter)
      (*value)--;
    else
      (*value)++;
      
    update();
    delay(10);
  }
}

void loop()
{
  // start out at black (all off)
  color_morph(&redVal,   1); // transition to red
  color_morph(&greenVal, 1); // transition to yellow
  color_morph(&redVal,   0); // transition to green
  color_morph(&blueVal,  1); // transition to aqua
  color_morph(&redVal,   1); // transition to white
  color_morph(&greenVal, 0); // transition to violet
  color_morph(&redVal,   0); // transition to blue
  color_morph(&blueVal,  0); // transition to black (all off)
}
