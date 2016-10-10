const int SENSOR_PIN = A2;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  
  Serial.begin(9600);
  Serial.println("HC-06 connected!");
}

void loop() {
  byte tempC = (analogRead(SENSOR_PIN) * 5.0 * 100.0) / 1024.0;
  Serial.println(String(tempC) + " °C");
  delay(3000);
}
