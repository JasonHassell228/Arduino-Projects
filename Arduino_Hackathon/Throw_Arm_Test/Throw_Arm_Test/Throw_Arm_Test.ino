#include <Adafruit_MotorShield.h>
#include <L298N.h>

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENA 9
#define ENB 10

L298N motor(ENA, IN1, IN2); // First motor 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setSpeed(80);
}

void loop() {
  // put your main code here, to run repeatedly:

  motor.forward();
  Serial.println("Begun moving!\n");
  Serial.println(motor.isMoving());

  delay(3000);

  motor.stop();

  delay(4000); 
  
  
  
}
