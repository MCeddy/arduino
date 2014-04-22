int ledPinBlink = 13;
int ledPinTaster = 10;
int ledPinInvertBlink = 2;
int tasterPin = 8;
int tasterStatus;
int interval = 2000;
unsigned long prev;
int ledStatus = LOW;

void setup()
{
  pinMode(ledPinBlink, OUTPUT);
  pinMode(ledPinTaster, OUTPUT);
  pinMode(ledPinInvertBlink, OUTPUT);
  pinMode(tasterPin, INPUT);
  
  prev = millis();
}

void loop()
{
  if ((millis() - prev) > interval)
  {
    prev = millis();
    ledStatus = !ledStatus;
    digitalWrite(ledPinBlink, ledStatus);
    digitalWrite(ledPinInvertBlink, !ledStatus);
  }
  
  tasterStatus = digitalRead(tasterPin);
  digitalWrite(ledPinTaster, tasterStatus);
}
