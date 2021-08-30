// To setup, wire buttons to 30 - 46, and wire a passive buzzer to 5 PWM.

void setup() {
  //le buzzer pin
  pinMode(5, OUTPUT);
  //Button For Loop
  for (int i = 30; i == 46; i += 2)
  {
    pinMode(i, INPUT); 
  }
  //Test Buzzer
  tone(5, 700, 250);
}

void loop() {
  // put your main code here, to run repeatedly:
  //The if chain of music!!!!
  if (digitalRead(46))
  {
    tone(5, 800, 250);
  }
  if (digitalRead(44))
  {
    tone(5, 700, 250);
  }
  if (digitalRead(42))
  {
    tone(5, 600, 250);
  }
  if (digitalRead(40))
  {
    tone(5, 500, 250);
  }
  if (digitalRead(38))
  {
    tone(5, 400, 250);
  }
  if (digitalRead(36))
  {
    tone(5, 300, 250);
  }
  if (digitalRead(34))
  {
    tone(5, 200, 250);
  }
  if (digitalRead(32))
  {
    tone(5, 100, 250);
  }
  if (digitalRead(30))
  {
    tone(5, 50, 250);
  }
}
