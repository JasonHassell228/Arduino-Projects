    /*
    * Arduino Wireless Communication Tutorial
    *     Example 1 - Transmitter Code
    *                
    * by Dejan Nedelkovski, www.HowToMechatronics.com
    * 
    * Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
    */
    
    // 3.3v - VCC
    // GND - GND
    // 8 - CSN
    // 7 - CE
    // 13 - SCK
    // 11 - MOSI
    // 12 - MISO
    
    #include <SPI.h>
    #include <nRF24L01.h>
    #include <RF24.h>
    
    int xPosition = 0;
    int yPosition = 0;
    int buttonPin = 7;
    int engineButton = 6;
    int buttonState = 0;
    int xPin = A1;
    int yPin = A0;
    
    RF24 radio(7, 8); // CE, CSN
    const byte address[6] = "00001";
    void setup() {
      //Radio
      radio.begin();
      radio.openWritingPipe(address);
      radio.setPALevel(RF24_PA_MIN);
      radio.stopListening();

      //Other shit
      // initialize serial communications at 9600 bps:
      Serial.begin(9600); 
      
      pinMode(xPin, INPUT);
      pinMode(yPin, INPUT);
      pinMode(engineButton, OUTPUT);
    }
    void loop() {
      // Radio stuff
      /*
      const char text[] = "Hello World";
      radio.write(&text, sizeof(text));
      */

      // Car stuff
      xPosition = analogRead(xPin);
      yPosition = analogRead(yPin);
      
      buttonState = digitalRead(buttonPin);
      /*
      Serial.print("X: ");
      Serial.print(xPosition);
      Serial.print(" | Y: ");
      Serial.print(yPosition);
      Serial.print(" | Button: ");
      Serial.println(buttonState);
      */

      int forward = 3;
      int left = 2;
      int right = 1;
      //radio.stopListening();
      if(xPosition <= 50){
        //digitalWrite(engineButton, HIGH);
        Serial.print(" engine on");
        Serial.print(radio.write(&forward, sizeof(int)));
      }
      else{
        //digitalWrite(engineButton, LOW);
        Serial.print(" engine off");
      }
    
      if (yPosition >= 1000){
        //stepper.step(-10);
        Serial.print(" Turning Left");
        Serial.print(radio.write(&left, sizeof(int)));
      }
    
      else if (yPosition <= 50)
      {
        //stepper.step(0);
        Serial.print(" Turning right");
        Serial.print(radio.write(&right, sizeof(int)));
      }
    
      else {
        //stepper.step(0);
        Serial.print(" Turning straight");
      }
      Serial.print("\n");
      //radio.startListening();
      
    }





/*
    // C-A-R--C-O-D-E

    // With Wires Forward
// Y=1023 for Forward
// Y=0 for Backwards
// Y=513 for Neutral
// X=0 for Left
// X=1023 for Right
// X=491 for Neutral

#include <Stepper.h>
#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
Stepper stepper(STEPS, 8, 10, 9, 11);







void setup() {
  

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  
  // For versions prior to Arduino 1.0.1
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);

  stepper.setSpeed(100);
  
}

void loop() {
  
  
  
//  else if(xPosition >= 419 && xPosition < 950 || xPosition <= 419 && xPosition > 50){
//  else if(xPosition > 80 && xPosition < 950){
//    stepper.step(0);
//  }
  
  
  delay(100); // add some delay between reads
}

*/
