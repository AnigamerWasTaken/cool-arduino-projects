void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  Serial.begin(3600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(String(spinDetect("clockwise", 22, 24)));
}

bool spinDetect(int spinDirection, int joyX, int joyY)
{
  if (spinDirection == "clockwise")
  {
    if (analogRead(joyX) == HIGH && analogRead(joyY) == LOW)
    {
      delay(500);
      if (analogRead(joyY) == HIGH && analogRead(joyX) == LOW)
      {
        return true;
      }
    }
  }
  if (spinDirection == "counterClockwise")
  {
    if (analogRead(joyY) == LOW && analogRead(joyX) == HIGH)
    {
      delay(500);
      if (analogRead(joyX) == LOW && analogRead(joyY) == HIGH)
      {
        return true;
      }
    }
  }
  return false;
}
