#include <Arduino.h>

// Pin Definitions based on diagram
const int PIR_PIN = 26;    // PIR Sensor output
const int LED_PIN = 13;    // Red LED
const int BUZZER_PIN = 14; // Piezo Buzzer

// Alarm Settings
const int ALARM_FREQ = 2000; // 2kHz tone
const int RESOLUTION = 8;    // 8-bit resolution

void setup() {
  Serial.begin(115200);
  
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Setup PWM for the buzzer (using new ESP32 3.0+ syntax)
  ledcAttach(BUZZER_PIN, ALARM_FREQ, RESOLUTION);
  
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);

  if (motionDetected == HIGH) {
    Serial.println("!!! MOTION DETECTED !!!");
    
    // Trigger Alarm Sequence
    triggerAlarm();
  } else {
    // Ensure everything is off when quiet
    digitalWrite(LED_PIN, LOW);
    ledcWrite(BUZZER_PIN, 0); 
  }
  
  delay(100); // Short delay for stability
}

void triggerAlarm() {
  // Flash LED and beep the buzzer 5 times
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN, HIGH);
    ledcWrite(BUZZER_PIN, 127); // 50% duty cycle tone
  

  }
}