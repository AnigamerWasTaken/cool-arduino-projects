#include <LiquidCrystal.h>

//Simply get a lcd and connect the AO (contrast) to PWM 5, and all other pins of the lcd from 22 - 42.  
//And you are done! This was originally made for my mom, but you can show this to anyone!

LiquidCrystal lcd(22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42);
byte heart[8] = {
  B01010,
  B10101,
  B10001,
  B10001,
  B01010,
  B00100,
  B00000,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  analogWrite(5, 128);
  lcd.begin(16, 2);\
  lcd.write(byte(0));
}

void loop() {
  // put your main code here, to run repeatedly:

}
