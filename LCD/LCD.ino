#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define SENSOR_PIN A3

#define I2C_ADDR 0x27
#define Rs_pin 0
#define Rw_pin 1
#define En_pin 2
#define BACKLIGHT_PIN 3
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  
  lcd.begin (20,4);

  // LCD Backlight ON
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);

  lcd.home (); // go home on LCD
  lcd.print("Scr.at");
}

void loop() {
  byte tempC = (analogRead(SENSOR_PIN) * 5.0 * 100.0) / 1024.0;

  lcd.setCursor(0, 2);
  lcd.print("temperature: ");
  lcd.print(String(tempC));
  
  delay(1500);
}
