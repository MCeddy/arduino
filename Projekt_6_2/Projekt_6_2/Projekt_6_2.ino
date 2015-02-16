#include <OneButton.h>

const int buttonPin = 11;
const int taktPin = 8; //SH_CP
const int speicherPin = 9; //ST_CP
const int datenPin = 10; //DS

boolean isRunning = true;
int counter = 0;
int interval = 100;
unsigned long prev;
OneButton button(buttonPin, false);

void setup() {
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  button.attachClick(buttonClicked);
  button.attachDoubleClick(buttonDoubleClicked);
  
  prev = millis();
}

void loop() {
  button.tick();
  
  if (!isRunning) {
    return;
  }
  
  if ((millis() - prev) < interval) {
    return;
  }
  
  prev = millis();
  
  digitalWrite(speicherPin, LOW);
  shiftOut(datenPin, taktPin, MSBFIRST, counter);
  digitalWrite(speicherPin, HIGH);
  
  counter++;
  if (counter > 255) {
    counter = 0;
  }
}

void buttonClicked() {
  if (isRunning) {
    interval += 100;
  
    if (interval > 600) {
      isRunning = false;
      interval = 100;
    }
  }
  else { // not running
    isRunning = true;
  }
}

void buttonDoubleClicked() {
  // reset counter
  counter = 0;
}
