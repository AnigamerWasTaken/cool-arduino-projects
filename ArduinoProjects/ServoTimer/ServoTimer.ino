#include <Servo.h>
Servo srv;
int pos;
// To set up this circut, wire a servo's data (orange) wire to PWM Pin 9.
// Then connect the power lines of the servo like you would normally (red= 3.3v, black = ground)
// Next, get an active speaker (the polarized one) and wire + to pin 36, and ground to ground.
// Now, upload the code to the arduino and enjoy your timer! This is configured to be around 1 minute. To change timing, change the delay at the end of the loop. 
void setup() {
  // put your setup code here, to run once:
  pinMode(36, OUTPUT);
  srv.attach(9);
  srv.write(0);
  pos = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  pos++;
  srv.write(pos);
  if (pos == 180)
  {
    digitalWrite(36, HIGH);
    delay(3000);
    digitalWrite(36, LOW);
    pos = 0;
    srv.write(0);
  }
  delay(250);
}
