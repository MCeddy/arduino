int ledPin = 13;
int tasterPin = 8;
int tasterStatus;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(tasterPin, INPUT);
}

void loop()
{
  tasterStatus = digitalRead(tasterPin);
  
  if (tasterStatus == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
