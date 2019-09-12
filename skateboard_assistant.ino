


#include <Mouse.h>
#include <math.h>
const int trigpinR = 8; //Trig for Right Sensor
const int echopinR = 7; //Echo for Right Sensor
const int trigpinL = 4; //Trig for Left Sensor
const int echopinL = 3; //Echo for Left Sensor
const int LEDR = 5; //the LED output indicating swerve right
const int LEDL = 6; //the LED output for indicating swerve left
long durationR; //time for right sensor to receive wave
long durationL; //time for left sensor to receive wave
float distanceR;
float distanceL;
float diff;

void setup()
{
  pinMode(trigpinR,OUTPUT);
  pinMode(echopinR,INPUT);
  pinMode(trigpinL,OUTPUT);
  pinMode(echopinL,INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDL, OUTPUT);
  Serial.begin(9600);
 
}
void loop()
{
  delay(1000);


  //Calculating distance from right ultrasonic sensor
  digitalWrite(trigpinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpinR, LOW);
  durationR = pulseIn(echopinR, HIGH);
  distanceR = durationR * 0.017;
  Serial.println(distanceR);


  //Calculating distance from left ultrasonic sensor
  digitalWrite(trigpinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpinL, LOW);
  durationL = pulseIn(echopinL, HIGH);
  distanceL = durationL * 0.017;
  Serial.println(distanceL);
//if distanceL >2 and <30 and distanceR > 2 andQA < 30

  
  diff = distanceR - distanceL; 
  if(distanceL > 0 && distanceL < 100 && distanceR > 0 && distanceR < 100)
  {
    if(distanceR > distanceL)
    {
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDL, LOW);
      Serial.println("Right");
      
    }

    else if(distanceL < distanceR)
    {
      digitalWrite(LEDL, HIGH);
      digitalWrite(LEDR, LOW);
      Serial.println("Left");
    }

    else if(abs(diff)<=0.1)
    {
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDL, HIGH);
      Serial.println("Jump");
    }
  }
  else
  {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDL, LOW);
    Serial.println("Clear");
  }
  
  
}


  /*
  digitalWrite(trigpinR, LOW);
  digitalWrite(trigpinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpinR,HIGH);
  digitalWrite(trigpinL,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpinR,LOW);
  digitalWrite (trigpinL,LOW);
  durationR = pulseIn(echopinR, HIGH);
  distanceR = durationR * 0.017;
  Serial.println(distanceR);
  durationL = pulseIn(echopinL, HIGH);
  distanceL = durationL * 0.017;
  Serial.println(distanceL);
  */


