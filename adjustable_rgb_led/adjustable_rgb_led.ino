#define POT_PIN A5
#define LED1 8
#define LED2 9
#define LED3 10

#define ON HIGH
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

int rgbOut[] = { 0, 0, 0 };
int val;
int rawVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  rawVal = analogRead(POT_PIN);
  val = floor(rawVal / 100);

  Serial.print(rawVal);
  Serial.print(":");
  Serial.println(val);

  const boolean* color = COLORS[val];
  setColor(color);

  // // red, green, blue...
  // for (int i = 0; i < 3; i++) {
  //     rgbOut[i] = 0;
  // }
  // int2rgb(val, rgbOut);
  // Serial.println(val);
  delay(1000);
}

void setColor(const boolean* color) {
  digitalWrite(LED1, color[0]);
  digitalWrite(LED2, color[1]);
  digitalWrite(LED3, color[2]);
}

// void setColor(boolean* color) {
//   const boolean *color2 = color;
//   setColor(color2);
// }

// void setColor(int* led, boolean* color) {
//     for (int i = 0; i &lt; 3; i++) {   
//         digitalWrite(led[i], color[i]);
//     }
// }

// void int2rgb(int val, const int *rgbOut) {
//     // do some magic
//     // ??
//     // profit!
// }