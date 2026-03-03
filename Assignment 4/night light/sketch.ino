#include <Arduino.h>

// Pin Definitions based on your ESP32 diagram
const int LDR_PIN = 34;  // LDR connected to GPIO 34 (Analog AO)
const int LED_PIN = 13;   // LED connected to GPIO 5

// PWM Settings
const int FREQ = 5000;     // 5 kHz frequency
const int RESOLUTION = 10; // 10-bit resolution (0-1023)

void setup() {
  Serial.begin(115200);

  // New ESP32 Core 3.0+ Syntax:
  // ledcAttach(pin, frequency, resolution);
  ledcAttach(LED_PIN, FREQ, RESOLUTION);

  pinMode(LDR_PIN, INPUT);
}

void loop() {
  // Read light level (ESP32 ADC is 12-bit: 0 to 4095)
  int ldrValue = analogRead(LDR_PIN);
  
  // Convert LDR value to LED brightness
  // Darkness (high LDR value) -> Full Brightness (1023)
  // Light (low LDR value) -> LED Off (0)
  int brightness = map(ldrValue, 0, 4095, 0, 1023);

  // Apply brightness using the updated write function
  ledcWrite(LED_PIN, brightness);

  // Debugging output to Serial Monitor
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);

  delay(1000); 
}