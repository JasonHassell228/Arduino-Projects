// With Wires Forward
// Y=1023 for Forward
// Y=0 for Backwards
// Y=513 for Neutral
// X=0 for Left
// X=1023 for Right
// X=491 for Neutral
#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)

//Stepper stepper(STEPS, 3, 5, 4, 6);
int engineButton = 9;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define ENA 9
#define IN1 3
#define IN2 4
#define ENB 10
#define IN3 5
#define IN4 6

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

// 0⸮
int back = 4;
int forwards = 3;
int left = 2;
int right = 1;
int text = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(engineButton, OUTPUT);
//  stepper.setSpeed(20);
  // Radio Initialising
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  // Motor Initialising
  pinMode(ENA, OUTPUT); /* This is the first motor */
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); /* This is the second mototr */

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void moveForward(void) { // Sends voltages to move motors forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveBackward(void) { // As above. but backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stayStill(void)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft(void)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight(void)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void loop() {
//  radio.startListening();
  if (radio.available()) {
//      char text[32] = "";
//      radio.read(&text, sizeof(text)); 
  }
    Serial.println(radio.available());
    Serial.println("help me");
    radio.read(&text, sizeof(text));
    Serial.println(text);
      
    if(text == forwards){
      //digitalWrite(engineButton, HIGH);
      moveForward();
    }
    
    else if (text == left){
      //stepper.step(-3);
      turnLeft();
    }
    else if (text == right){
      //stepper.step(3);
      turnRight();
    }
    else if (text == back)
    {
      moveBackward();
    }

    else{
      //digitalWrite(engineButton, LOW);
      stayStill();
    }
  }
//  radio.stopListening();

  /*
  //else if(xPosition >= 419 && xPosition < 950 || xPosition <= 419 && xPosition > 50){
  else if(xPosition > 80 && xPosition < 950){
    stepper.step(0);
  }*/
//  
//  
//  delay(100); // add some delay between reads
//}
