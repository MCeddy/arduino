#include <Bounce2.h>

int ledPinRed = 13;
int ledPinYellow = 10;
int ledPinGreen = 2;
int tasterPin = 8;
boolean tasterStatus;
int interval = 100;
int tasterInterval = 5;
unsigned long prev;
int ledStatus = LOW;
Bounce debouncer = Bounce();

void setup()
{
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(tasterPin, INPUT);
  
  debouncer.attach(tasterPin);
  debouncer.interval(tasterInterval);
  
  prev = millis();
}

void loop()
{
  bool stateChanged = debouncer.update();
  int tasterWert = debouncer.read();
  
  if (stateChanged && (tasterWert == LOW))
  {
    tasterStatus = !tasterStatus;
  }
  
  if (tasterStatus)
  {
    if ((millis() - prev) > interval)
    {
      prev = millis();
      ledStatus = !ledStatus;
      
      digitalWrite(ledPinRed, ledStatus);
      digitalWrite(ledPinYellow, !ledStatus);
      digitalWrite(ledPinGreen, ledStatus);
    }
  }
  else
  {
    //turn off all LEDs
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinYellow, LOW);
    digitalWrite(ledPinGreen, LOW);
  }
}
