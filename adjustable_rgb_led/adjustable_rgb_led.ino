#include <math.h>

#define POT_PIN A5
#define LED1_PIN 8
#define LED2_PIN 9
#define LED3_PIN 10

#define ON  HIGH
#define OFF LOW

const boolean RED[]     = { ON, OFF, OFF };
const boolean GREEN[]   = { OFF, ON, OFF }; 
const boolean BLUE[]    = { OFF, OFF, ON };
const boolean YELLOW[]  = { ON, ON, OFF };
const boolean CYAN[]    = { OFF, ON, ON };
const boolean MAGENTA[] = { ON, OFF, ON };
const boolean WHITE[]   = { ON, ON, ON };
const boolean BLACK[]   = { OFF, OFF, OFF };
const boolean* COLORS[] = { WHITE, WHITE, GREEN, CYAN, BLUE, MAGENTA, RED, YELLOW, BLACK, BLACK };

int val;
int rawVal;

void setup() {
  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

void loop() {
  rawVal = analogRead(POT_PIN);
  val = map(rawVal, 0, 1023, 0, 10);
  setColor(COLORS[val]);

  Serial.print(rawVal);
  Serial.print(":");
  Serial.println(val);

  delay(1000);
}

void setColor(const boolean* color) {
  digitalWrite(LED1_PIN, color[0]);
  digitalWrite(LED2_PIN, color[1]);
  digitalWrite(LED3_PIN, color[2]);
}
