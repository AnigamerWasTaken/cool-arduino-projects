void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(spinDetect("clockwise", A0, A1));
  
}

bool spinDetect(String spinDirection, int joyX, int joyY)
{
  if (spinDirection == "clockwise")
  {
    if (analogRead(joyX) > 512 && analogRead(joyY) == 0)
    {
      delay(500);
      if (analogRead(joyY) > 512 && analogRead(joyX) == 0)
      {
        return true;
      }
    }
  }
  if (spinDirection == "counterClockwise")
  {
    if (analogRead(joyY) == 0 && analogRead(joyX) > 512)
    {
      delay(500);
      if (analogRead(joyX) == 0 && analogRead(joyY) > 512)
      {
        return true;
      }
    }
  }
  return false;
}
