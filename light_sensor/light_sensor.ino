const int SENSOR_PIN = A1;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(SENSOR_PIN);
  Serial.println(light);
  delay(1000);
}
