#include <IRremote.h>
#include <LiquidCrystal.h>
//To set this up, get a LCD and connect the VO pin to 5 PWM, and all subsequnt pins to 22 - 42.
//Then, get a IR reciver and connect it to pin 11.
//The base of this script is based on the adeept IR remote script for the tutorial pack for their atmega2560 arduino model. Thanks adeept! 
int RECV_PIN = 11;//The definition of the infrared receiver pin 11
IRrecv irrecv(RECV_PIN);
LiquidCrystal lcd(22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42);
decode_results results;
String code;

void setup()
{
  Serial.begin(9600); //Open serial 
  irrecv.enableIRIn(); // Initialization infrared receiver
  lcd.begin(16, 2);
  pinMode(5, OUTPUT);
  analogWrite(5, 75);
  lcd.print("ENTER A CODE.");
  lcd.setCursor(0, 1);
} 

void loop() 
{
  if (irrecv.decode(&results)) {
    if (results.value == 0xE318261B) //1
    {
      code += String(1);
      lcd.print(1);
    }
    if (results.value == 0x511DBB) //2
    {
      code += String(2);
      lcd.print(2);
    }
    if (results.value == 0xEE886D7F) //3
    {
      code += String(3);
      lcd.print(3);
    }
    if (results.value == 0x52A3D41F) //4
    {
      code += String(4);
      lcd.print(4);
    }
    if (results.value == 0xD7E84B1B) //5
    {
      code += String(5);
      lcd.print(5);
    }
    if (results.value == 0x20FE4DBB) //6
    {
      code += String(6);
      lcd.print(6);
    }
    if (results.value == 0xF076C13B) //7
    {
      code += String(7);
      lcd.print(7);
    }
    if (results.value == 0xA3C8EDDB) //8
    {
      code += String(8);
      lcd.print(8);
    }
    if (results.value == 0xE5CFBD7F) //9
    {
      code += String(9);
      lcd.print(9);
    } 
    if (results.value == 0x97483BFB) //0
    {
      code += String(0);
      lcd.print(0);
    } 
    if (results.value == 0x488F3CBB) //OK
    {
      if (code == "254125")
      {
        lcd.clear();
        lcd.print("Correct!");
      }
      else
      {
        lcd.clear();
        lcd.print("Wrong!");
      }
    }
    Serial.println(results.value, HEX);//Wrap output in hex receive code
    Serial.println();//For ease of viewing the output to add a blank line
    irrecv.resume(); //Receiving the next value
  }
}
