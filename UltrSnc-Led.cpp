#include <Arduino.h>

//This program will take input from an ultrasonic sensor and light up 3 LEDs systematically as 
//the distance reduces

const int trigPin = 10;
const int echoPin = 13;

float time, distance;

void setup ()
{
 //setup Ultrasonic sensor
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 //setup LED
 int i;
  for (i = 2;i != 5;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }

}

void loop()
{
    float baseDistance = 100.00;
    //send a pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin, LOW);

    //measure time taken to receive signal
    time = pulseIn(echoPin, HIGH);

    //calculate distance
    distance = (time/2) * 0.0343;

    //send results to serial monitor
    if (distance >= 400 || distance <= 2)
        {Serial.println("Distance is out of Range!");delay(500);}
    else
    {
        Serial.print("Distance = ");
        Serial.print(distance);
        Serial.println(" cm");
        delay(500);
    }

    //Show proximity using LED

    if(distance == baseDistance || distance > baseDistance)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  else if(distance <= (baseDistance/2) && distance > (baseDistance/4))
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  }

  else if(distance > (baseDistance/10) && distance < (baseDistance/4))
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  }

  else if(distance < baseDistance/10)
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  }

  delay(500);


}