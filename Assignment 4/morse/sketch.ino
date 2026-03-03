const int BUZZER_PIN = 23; 
const int DOT_DURATION = 200; 

// Morse code dictionary for A-Z and 0-9
const char* morseTable[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

const char* morseNumbers[] = {
  "-----", ".----", "..---", "...--", "....-", // 0-4
  ".....", "-....", "--...", "---..", "----."  // 5-9
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Enter text to convert to Morse Code:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase();
    
    for (int i = 0; i < input.length(); i++) {
      char c = input[i];
      
      if (c >= 'A' && c <= 'Z') {
        playMorse(morseTable[c - 'A']);
      } else if (c >= '0' && c <= '9') {
        playMorse(morseNumbers[c - '0']);
      } else if (c == ' ') {
        delay(DOT_DURATION * 7); // Space between words
      }
      
      delay(DOT_DURATION * 3); // Space between letters
    }
  }
}

void playMorse(const char* sequence) {
  for (int i = 0; sequence[i] != '\0'; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    
    if (sequence[i] == '.') {
      delay(DOT_DURATION);
    } else if (sequence[i] == '-') {
      delay(DOT_DURATION * 3);
    }
    
    digitalWrite(BUZZER_PIN, LOW);
    delay(DOT_DURATION); // Space between symbols in same letter
  }
}