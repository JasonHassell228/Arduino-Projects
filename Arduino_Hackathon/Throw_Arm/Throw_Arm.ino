// defines pins numbers
#include <Servo.h>
const int trigPin = 11;
const int echoPin = 10;
// defines variables
long duration;
int distance;
Servo myservo;
int thrown = 0;
void setup()
{
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(9);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(12, OUTPUT);
}
void fling() {
  //tone(12, 1000, 500);
  myservo.write(150);
  delay(1000);
  myservo.write(30);
}
void sense() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  if(distance > 40) {
    thrown = 0;
  }
  // Prints the distance on the Serial Monitor
  if(distance < 40 && thrown == 0) {
    fling();
    thrown = 1;
  }
}
void loop()
{
  sense();
}
