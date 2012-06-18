// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This is a simple test app for some cheap RF transmitter and receiver hardware.
// RF Transmitter: http://www.sparkfun.com/commerce/product_info.php?products_id=8945
// RF Receiver: http://www.sparkfun.com/commerce/product_info.php?products_id=8948

#include <SoftwareSerial.h>

// This says whether you are building the transmistor or reciever.
// Only one of these should be defined.
// #define TRANSMITTER
#define RECEIVER

// Arduino digital pins
#define BUTTON_PIN  7
#define LED_PIN     13
#define RX_PIN 2
#define TX_PIN 3

// Button hardware is setup so the button goes LOW when pressed
#define BUTTON_PRESSED LOW
#define BUTTON_NOT_PRESSED HIGH

SoftwareSerial sserial(RX_PIN, TX_PIN); // RX, TX

void blinkLed() {
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
}

void setup() {
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  #ifdef TRANSMITTER
  digitalWrite(BUTTON_PIN, HIGH);
  #endif

  // #ifdef RECEIVER
  Serial.begin(9600);
  sserial.begin(4800);
  // #endif

  // Serial.begin(2400);  // Hardware supports up to 2400, but 1200 gives longer range
}

#ifdef TRANSMITTER
void loop() {
  static int prev_button = BUTTON_NOT_PRESSED;  // Previous button press value
  int        cur_button;                        // Current button press value

  cur_button = digitalRead(BUTTON_PIN);

  int sendMsg = 71;

  if ((prev_button == BUTTON_NOT_PRESSED) && (cur_button == BUTTON_PRESSED)) {
    writeUInt(sserial, sendMsg);
    Serial.write("sent: ");
    Serial.println(sendMsg);
    blinkLed();
  }

  delay(15); // Debounce button
  prev_button = cur_button;
}
#endif //TRANSMITTER

#ifdef RECEIVER
void loop() {
  // unsigned int msg = readUInt(true);
  if (readUInt(sserial, true) == 71) { // Check to see if we got the 71 test number
    blinkLed();
    Serial.println("received message!");
  }

  // blinkLed();
  // delay(1000);
}
#endif //RECEIVER
