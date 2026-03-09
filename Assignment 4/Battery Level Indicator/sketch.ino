#include <Arduino.h>

// Pin Definitions based on your diagram
const int POT_PIN = 15; // Simulated battery voltage
const int ledPins[] = {26, 27, 14, 12, 13}; // LED bar graph pins
const int numLeds = 5;

void setup() {
  Serial.begin(115200);
  
  // Initialize all LED pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // Read simulated voltage (0 to 4095 on ESP32)
  int analogValue = analogRead(POT_PIN);
  
  // Map the analog value to the number of LEDs to light up (0 to 5)
  int ledLevel = map(analogValue, 0, 4095, 0, numLeds);

  // Update the LED bar graph
  for (int i = 0; i < numLeds; i++) {
    // If the current LED index is less than the level, turn it on
    if (i < ledLevel) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Debugging info
  float simulatedVoltage = (analogValue / 4095.0) * 3.3;
  Serial.print("Voltage: ");
  Serial.print(simulatedVoltage);
  Serial.print("V | LEDs Lit: ");
  Serial.println(ledLevel);

  delay(50); // Small delay for smooth updates
}