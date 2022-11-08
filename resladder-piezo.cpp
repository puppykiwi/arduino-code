#include <Arduino.h>

//This program will take input from a resistor ladder and play a corresponding note

//array with notes to play
int notes[] = {262,294,330,349};

void setup()
{
Serial.begin(9600);
}

void loop()
{
int val = analogRead(0);
Serial.println(val);

//plays a tone depending on the val
if (val > 1010)
{tone(8,notes[0]);}

else if(val > 970 & val < 1010)
{tone(8,notes[1]);}

else if(val > 820 & val < 970)
{tone(8,notes[2]);}

else if(val > 450 & val < 550)
{tone(8,notes[3]);}

else
{noTone(8);}
}
