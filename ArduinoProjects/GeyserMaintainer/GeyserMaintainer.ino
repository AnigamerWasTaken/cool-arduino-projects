#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42);
//How to assemble:
//Connect a lc's VO to 8 PWM and RS - D7 to 22 - 42.
//Connect pushbuttons to 46 - 52
//Enjoy!
//How to play:
//Hold each button to prevent the geysers from bursting.
//Geyser Images
byte stage1Geyser[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte stage2Geyser[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B11111
};

byte stage3Geyser[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00100,
  B01110,
  B11111
};

byte stage4Geyser[] = {
  B00000,
  B01010,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B11111
};
int geyser1Timer = 5;
int geyser2Timer = 12;
int geyser3Timer = 9;
int geyser4Timer = 12;

int randSeed = 0;

void setup() {
  // put your setup code here, to run once:
  randomSeed(23507909);
  lcd.begin(16, 2);
  pinMode(8, OUTPUT);
  analogWrite(8, 75);
  pinMode(46, INPUT);
  pinMode(48, INPUT);
  pinMode(50, INPUT);
  pinMode(52, INPUT);
  Serial.begin(9600);
  
  lcd.createChar(0, stage1Geyser);
  lcd.createChar(1, stage2Geyser);
  lcd.createChar(2, stage3Geyser);
  lcd.createChar(3, stage4Geyser);
}

void loop() {
  // put your main code here, to run repeatedly:
  

 lcd.setCursor(3, 1);
 lcd.write(byte(int(geyser1Timer / 5) - 1));
 lcd.setCursor(6, 1);
 lcd.write(byte(int(geyser2Timer / 5) - 1));
 lcd.setCursor(9, 1);
 lcd.write(byte(int(geyser3Timer / 5) - 1));
 lcd.setCursor(12, 1);
 lcd.write(byte(int(geyser4Timer / 5) - 1));

 if (digitalRead(46) == 1)
 {
   geyser1Timer = 5;
 }
 if (digitalRead(48) == 1)
 {
   geyser2Timer = 5;
 }
 
 if (digitalRead(50) == 1)
 {
   geyser3Timer = 5;
 }

 if (digitalRead(52) == 1)
 {
   geyser4Timer = 5;
 }

 delay(500);

 if (geyser1Timer >= 20 || geyser2Timer >= 20 || geyser3Timer >= 20 || geyser4Timer >= 20)
 {
  lcd.home();
  lcd.print("Game Over! Score: " + String(millis() / 1000));
  geyser1Timer = 5;
  geyser2Timer = 12;
  geyser3Timer = 9;
  geyser4Timer = 12;
  delay(1000);
  lcd.clear();

 }
 geyser1Timer++;
 geyser2Timer++;
 geyser3Timer++;
 geyser4Timer++;
}
