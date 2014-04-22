#include <Bounce2.h>

int ledPinRed = 13;
int ledPinYellow = 10;
int ledPinGreen = 2;
int tasterPin = 8;
byte ledStatus = 0; //0 = off; 1 = red LED; 2 = yellow LED; 3 = green LED;
int tasterInterval = 5;
Bounce debouncer = Bounce();

void setup()
{
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(tasterPin, INPUT);
  
  debouncer.attach(tasterPin);
  debouncer.interval(tasterInterval);
}

void loop()
{
  bool stateChanged = debouncer.update();
  int tasterWert = debouncer.read();
  
  if (stateChanged && (tasterWert == LOW)) //taster status changed
  {
    ledStatus++;
    
    if (ledStatus > 3)
    {
      //reset
      ledStatus = 0;
    }
    
    //turn off all LEDs
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinYellow, LOW);
    digitalWrite(ledPinGreen, LOW);
    
    switch(ledStatus)
    {
      case 0:
        break;
      case 1:
        digitalWrite(ledPinRed, HIGH);
        break;
      case 2:
        digitalWrite(ledPinYellow, HIGH);
        break;
      case 3:
        digitalWrite(ledPinGreen, HIGH);
        break;
    }
  }
}
