#include <Arduino.h>

//This program will receive input from an LM35 temp sensor and 
//will light up 3 leds based on the temperature (3 = high : 1 = low)

const int sensPin = A0;
const float baseTemp = 27;

void setup() 
{
  Serial.begin(9600);

  int i;
  for (i = 2;i != 5;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }


}

void loop() 
{ 
  int sensVal = analogRead(sensPin);
  Serial.print("sensorValue: ");
  Serial.print(sensVal);

  float voltage = sensVal * (5.0 / 1023.0);
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage*100);
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if(temperature < baseTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  else if(temperature >= baseTemp+2 && temperature < baseTemp+4)
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  }

  else if(temperature >= baseTemp+4 && temperature < baseTemp+6)
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  }

  else if(temperature >= baseTemp+6)
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  }

  delay(500);

}