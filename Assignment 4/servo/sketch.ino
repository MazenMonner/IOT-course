#include <ESP32Servo.h>

// Pin Definitions based on the diagram
const int POT_PIN = 35;   // Potentiometer signal
const int SERVO_PIN = 19; // Servo signal

Servo myServo;

void setup() {
  Serial.begin(115200);

  // Attach the servo to the specified pin
  // Note: Standard servos use a pulse width of 500us to 2400us
  myServo.attach(SERVO_PIN, 500, 2400); 
  
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // Read the potentiometer (ESP32 ADC is 12-bit: 0 to 4095)
  int potValue = analogRead(POT_PIN);

  // Map the ADC value (0-4095) to degrees (0-180)
  int angle = map(potValue, 0, 4095, 0, 180);

  // Move the servo to the calculated angle
  myServo.write(angle);

  // Debugging output to Serial Monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" -> Angle: ");
  Serial.println(angle);

  delay(1000); // Small delay for servo stability
}