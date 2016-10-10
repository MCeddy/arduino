const int HUMIDITY_PIN = A0;
const int POWER_PIN = 8;

void setup() { 
  pinMode(HUMIDITY_PIN, INPUT);
  pinMode(POWER_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int humidityValue = getHumidityValue(POWER_PIN, HUMIDITY_PIN);
  Serial.println(humidityValue);
  delay(3000);
}

int getHumidityValue(int powerPin, int sensorPin) {
  digitalWrite(powerPin, HIGH);
  delay(500);
  int sensorValue = analogRead(sensorPin);
  digitalWrite(powerPin, LOW);
  return sensorValue;
}

