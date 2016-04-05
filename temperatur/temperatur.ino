float tempC;

const int tempPin = 0;
const int ledPin = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  tempC = (analogRead(tempPin) * 5.0 * 100.0) / 1024.0;
  Serial.println((byte) tempC);

  if (tempC < 20) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(3000);
}
