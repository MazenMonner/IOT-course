// Pin Definitions based on diagram
const int TOUCH_PIN = 4;   // ESP32 Touch0 is on GPIO 4
const int RELAY_PIN = 14;  // Relay control pin

// Threshold for touch detection
// Lower values = less sensitive. Values below 20 usually indicate a touch.
const int TOUCH_THRESHOLD = 30; 

bool relayState = false;
bool lastTouchState = false;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Start with relay OFF
  
  Serial.println("Touch Switch Initialized.");
}

void loop() {
  // Read the capacitive touch value
  int touchValue = touchRead(TOUCH_PIN);
  
  // Logic: touchValue drops significantly when touched
  bool isTouched = (touchValue < TOUCH_THRESHOLD);

  // Detect the moment the finger touches (state change)
  if (isTouched && !lastTouchState) {
    relayState = !relayState; // Toggle state
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
    
    Serial.print("Touch Detected! Value: ");
    Serial.print(touchValue);
    Serial.print(" | Relay is now: ");
    Serial.println(relayState ? "ON" : "OFF");
    
    delay(200); // Debounce delay
  }

  lastTouchState = isTouched;
  delay(100); // Small stability delay
}