int taktPin = 8; //SH_CP
int speicherPin = 9; //ST_CP
int datenPin = 10; //DS
int dataArray1[] = {1, 0, 1, 0, 1, 0, 1, 0};
int dataArray2[] = {0, 1, 0, 1, 0, 1, 0, 1};

void setup() {
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);
}

void loop() {
  resetPins();
  setPins(dataArray1);
  digitalWrite(speicherPin, HIGH);
  
  delay(250);
  
  resetPins();
  setPins(dataArray2);
  digitalWrite(speicherPin, HIGH);
  
  delay(250);
}

void resetPins() {
  digitalWrite(taktPin, LOW);
  digitalWrite(speicherPin, LOW);
  digitalWrite(datenPin, LOW);
}

void setPins(int data[]) {
  for (int i = 0; i < 8; i++) {
    resetPins();
    digitalWrite(datenPin, data[i]);
    delay(20);
    digitalWrite(taktPin, HIGH);
    delay(20);
  }
}
