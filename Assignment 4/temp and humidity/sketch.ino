#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions based on your diagram
#define DHTPIN 4     // DHT22 Data pin connected to GPIO 13
#define DHTTYPE DHT22   // Specifying the sensor type

// LCD Settings
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  
  // Initialize peripherals
  dht.begin();
  lcd.init();
  lcd.backlight();

  // Initial Boot Screen
  lcd.setCursor(0, 0);
  lcd.print("Mazen");
  lcd.setCursor(0, 1);
  lcd.print("is here");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Read temperature as Celsius

  // Check if any reads failed
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error  ");
    return;
  }

  // Display Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1); // 1 decimal place
  lcd.print((char)223); // Degree symbol
  lcd.print("C   ");

  // Display Humidity
  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(h, 1);
  lcd.print(" %    ");

  // Debug to Serial Monitor
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("C | Humidity: ");
  Serial.println(h);

  delay(2000); // Wait 2 seconds between measurements
}