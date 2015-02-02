
/*
Lab 4 - Waving Hi!
Parth Soni
CDIGF 2B03 Physical Computing S01
OCAD University
Created on [Feb 1 2015]
 
Based on:
Servo example embbeded within Arduino.
*/

#include <Servo.h> 
 
int ledPin = 11;
Servo myservo;  // create servo object to control a servo 
Servo another;
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  another.attach(10);
  pinMode (ledPin, OUTPUT);
} 
 
 
void loop() 
{ 
//  digitalWrite (ledPin, HIGH);
  for(pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
   another.write(pos);
   analogWrite(ledPin, pos*2);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
       another.write(pos);
   analogWrite(ledPin, pos/2);

    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 
