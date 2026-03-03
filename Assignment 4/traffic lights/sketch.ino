
#define red 19 
#define yellow 18
#define green 5
#define button 25


void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);

  Serial.begin(115200);
}

void loop() {

digitalWrite (green, LOW);
digitalWrite (red, HIGH);
delay(1000);
digitalWrite (red, LOW);
digitalWrite (yellow, HIGH);
delay(1000);
digitalWrite (yellow, LOW);
digitalWrite (green, HIGH);
delay(1000);
}


