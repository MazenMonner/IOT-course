#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions based on your diagram
const int TRIG_PIN = 5;  
const int ECHO_PIN = 18; 
const int LCD_ADDR = 0x27; // Standard I2C address

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setup() {
  Serial.begin(115200);
  
  // Ultrasonic Sensor Pin Setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // LCD Initialization
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mazen is here");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Trigger the ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the bounce-back time in microseconds
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate Distance
  // Speed of sound is ~0.0343 cm/us
  float distanceCm = duration * 0.0343 / 2;
  float distanceIn = distanceCm / 2.54;

  // Display to LCD
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distanceCm);
  lcd.print(" cm   "); // Extra spaces to clear old digits

  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distanceIn);
  lcd.print(" in   ");

  delay(500); // Half-second refresh rate
}