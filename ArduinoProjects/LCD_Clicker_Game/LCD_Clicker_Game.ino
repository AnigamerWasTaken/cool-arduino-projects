//To build this circut, connect a 16x2 LCD's rs, rw, enable, d0, d1, d2, d3, d4, d5, d6 and d7 pins to 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42
// Also, connect the contrast pin to 8 PWM!
// Also, connect a button to pin 44 and ground.
// Now you have your own clicker game!
#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42);
int score = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(46, INPUT);
  digitalWrite(44, HIGH);
  analogWrite(8, 85);
  lcd.begin(16, 2);
  lcd.print("Your score is:");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(44) == 0)
  {
    score++;
    lcd.clear();
    lcd.print("Your score is:");
    lcd.setCursor(0, 1);
    lcd.print(String(score));
    delay(250);
  }
  
}
