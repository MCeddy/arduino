const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("HC-06 connected!");
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    if (value == 0) {
      digitalWrite(LED_PIN, LOW);
    }
    else if (value == 1) {
      digitalWrite(LED_PIN, HIGH);
    }
  }
}
