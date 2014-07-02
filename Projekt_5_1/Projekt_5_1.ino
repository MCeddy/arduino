int ledPins[] = { 7, 8, 9, 10, 11, 12, 13 };
int delayTime = 90;

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
    blink(ledPins[i]);
  }
  
  for (int i = 6; i >= 0; i--) 
  {
    blink(ledPins[i]);
  }
}

void blink(int pin)
{
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
}
