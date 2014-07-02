int ledPins[] = { 7, 8, 9, 10, 11, 12, 13 };
int delayTime = 200;

void setup()
{
  for (int i = 0; i < 7; i++) 
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() 
{
  for (int i = 0; i < 7; i++) 
  {
    int pin = ledPins[i];
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
  }
}
