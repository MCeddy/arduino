int taktPin = 8; //SH_CP
int speicherPin = 9; //ST_CP
int datenPin = 10; //DS
int dataArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
int index = -1;

void setup() {
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);
}

void loop() {
  if (index > 7) {
    index = -1;
  }
  
  resetPins();
  changeArray(dataArray, index);
  setPins(dataArray);
  digitalWrite(speicherPin, HIGH);
  
  index++;
}

void changeArray(int data[], int index) {
  if (index > -1) {
    int iLedLeft = index;
    int iLedRight = 7 - index;
    
    //set LEDs
    for (int i = 0; i < 8; i++) {
      if ((i == iLedLeft) || (i == iLedRight)) {
        data[i] = 1;
      }
      else {
        data[i] = 0;
      }
    }
  }
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
    delay(5);
    digitalWrite(taktPin, HIGH);
    delay(5);
  }
}
