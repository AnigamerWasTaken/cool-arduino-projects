
#include <Servo.h>

//To assemble this circut, connect a side of a button to 53, and the other to ground. Connect another button to ground and 52
//Then, get a servo's + to 3.3v, - to ground, and and data to PWM 9.
// Now, get a buddy and have fun! To win, spam the button till the servo points to you. If a servo points at your side and then resets, you win!
// But, if a servo points to your opponent and then resets, they win.
Servo srv;
int button1Pin = 53;
int button2Pin = 52;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  digitalWrite(button1Pin, HIGH);
  digitalWrite(button2Pin, HIGH);
  Serial.begin(9600);
  srv.attach(9);
  srv.write(105);
  pos = 105;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(pos);
  if (digitalRead(button1Pin) == 0)
  {
    pos += 10;
    srv.write(pos);
    delay(250);
  }
  if (digitalRead(button2Pin) == 0)
  {
    pos -= 10;
    srv.write(pos);
    delay(250);
  }
  if (pos < 0 or pos > 175)
  {
    pos = 105;
    srv.write(pos);
    delay(1000);
  }
  
}
