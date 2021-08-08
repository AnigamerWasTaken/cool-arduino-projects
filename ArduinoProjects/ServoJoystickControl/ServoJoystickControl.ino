
#include <Servo.h>
Servo srv;
int pos = 35;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  srv.attach(9);
  srv.write(pos);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(pos);
  if (pos > 0 && analogRead(A0) == 0)
  {
    pos++;
  }
  if (pos < 180 && analogRead(A0) == 1023)
  {
    pos--;
  }
  srv.write(pos);
}
