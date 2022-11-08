/*
*This program should get input from the HC-SR04 sensor and depending on the distance
*light up LEDs (1LED = <distance : 3LEDs = >distance)
*and beep a piezo with the beep interval changing (high rate = small distance)
*/

#include <Arduino.h>

int trigPin = 12;
int echoPin = 13;
int piezoPin = 9;
int piezoFreq = 2300;
float time,distance;

void blink();
void buzz();
float dist();

void setup()
{
//ULTRSNC
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

//LED
int i;
for (i = 4; i != 8; i++)
{pinMode(i,OUTPUT);}

//PIEZO
pinMode(piezoPin,OUTPUT);
}

void loop()
{
distance = dist();
Serial.println(distance);

blink();

//buzz();
}

void blink()
{
if (distance > 100)
{
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
}

else if (distance < 100 && distance > 50)
{
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
}

else if (distance < 50 && distance > 25)
{
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
}

else if (distance < 25 && distance > 0)
{
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
}
}

void buzz ()
{

/*
*This function is supposed to make the piezo beep intermittently,
*however, calling any of the while loops pauses the sensor and therefore dynamic changing of beep interval is unimplemented 
*The FUNCTIONcall in loop() is COMMENTED
*/

while (distance > 100)
{noTone(piezoPin);}

while (distance < 100 && distance > 50)
{
delay(1000);
tone(piezoPin,piezoFreq);
}

while (distance < 50 && distance > 25)
{
delay(500);
tone(piezoPin,piezoFreq);
}

while (distance < 25 && distance > 0)
{
delay(100);
tone(piezoPin,piezoFreq);
}

}

float dist()
{
    //send pulse
    digitalWrite(trigPin, LOW);
    delay(20);
    digitalWrite(trigPin, HIGH);
    delay(20);
    digitalWrite(trigPin, LOW);
    
    //get distance
    time = pulseIn(echoPin, HIGH);
    float len = (time/2) * 0.0343;
    return(len);
}

