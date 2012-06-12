int pin = 13;
// volatile int state = LOW;

void setup()
{
  pinMode(pin, OUTPUT);
  attachInterrupt(0, turnOn, FALLING);
}

void loop()
{
  delay(2000);
  // digitalWrite(pin, state);
  digitalWrite(pin, LOW);
}

void turnOn()
{
  // state = !state;
  digitalWrite(pin, HIGH);
}
