#include <Arduino.h>

//This code allows a potentiometer to control the bightness of an led


int potVal;//stores potentiometer values
int ledVal;

void setup()
{
pinMode(A0,INPUT);
pinMode(9, OUTPUT);
}

void loop()
{
potVal = analogRead(0);
ledVal = map(potVal, 0,1023, 0,255);
analogWrite(9,ledVal);

}