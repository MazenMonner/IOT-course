#include <Arduino.h>

// Input Pins (Potentiometers)
const int POT_R = 32;
const int POT_G = 35;
const int POT_B = 33;

// Output Pins (RGB LED)
const int LED_R = 13;
const int LED_G = 12;
const int LED_B = 14;

// PWM Settings


void setup() {
  Serial.begin(115200);

  pinMode(POT_R, INPUT);
  pinMode(POT_G, INPUT);
  pinMode(POT_B, INPUT);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT); 
}


int readPot(int pin) {
  return map(analogRead(pin), 0, 1023, 0, 255);
}

void loop() {

  analogWrite(LED_R,readPot(POT_R));
  analogWrite( LED_G,readPot(POT_G));
  analogWrite( LED_B,readPot(POT_B));
  delay(1000);

}
