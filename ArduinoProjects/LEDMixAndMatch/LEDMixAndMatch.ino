 // To setup, connect an RGB LED to 4, 5, and 6, and then connect buttons to 40, 42, 44, and 46.
//Variable Decralation

int r = 120;
int g = 120;
int b = 0;
int redPin = 4;
int greenPin = 5;
int bluePin = 6;
int redButton = 40;
int greenButton = 42;
int blueButton = 44;
int resetButton = 46;

void setup() {
  // pinmode time :)
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redButton, INPUT);
  pinMode(greenButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(resetButton, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(resetButton));
  // Button Detection
  if (digitalRead(redButton) == 0 && !r >= 255)
  {
    r += 5;
  }
  if (digitalRead(greenButton) == 0 && !g >= 255)
  {
    g += 5;
  }
  if (digitalRead(blueButton) == 0&& !b >= 255)
  {
    b += 5;
  }
    if (digitalRead(resetButton) == 0)
  {
    r = 0;
    g = 0;
    b = 0;
  }
  color(r, g, b);
}

void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, 255-red);     // PWM signal output   
     analogWrite(greenPin, 255-green); // PWM signal output
     analogWrite(bluePin, 255-blue);   // PWM signal output
}  
