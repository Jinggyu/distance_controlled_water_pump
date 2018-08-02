//***** THIS PROJECT USES THE ULTRASONIC DISTANCE SENSOR LIBRARY*****//

#include "Ultrasonic.h" // import the ultrasonic module

Ultrasonic ultrasonic(A3); // sensor pin#
const int motor= 10; // pump pin#

void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT); //sets the digital pin of pump as output
}

void loop()
{
  long RangeInCentimeters; // measure in cm
  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); 
  int distance = RangeInCentimeters;
  delay(200);
  //Serial.print(distance);//0~400cm   // print distance or not
  //Serial.println(" cm");

  // when close to the sensor (less than 50cm), pump turns on
  if(distance < 50){
    // the pump operates intermittently at the interval of 1.3sec
    digitalWrite(motor,HIGH); //turns the pump on
    delay(1000); 
    digitalWrite(motor,LOW); 
    delay(300); //
  }
  else{
    digitalWrite(motor,LOW); // if distance > 50cm, pump is not triggered
  }
  delay(200);
   
}
