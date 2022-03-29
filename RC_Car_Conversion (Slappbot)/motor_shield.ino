#include <AFMotor.h>

// pin 11 = Motors on/off

AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(8, OUTPUT);
//  pinMode(9, OUTPUT);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  
//  delay(3000);
//  motor1.run(FORWARD);
//  delay(1000);
//  motor1.run(RELEASE);
//  delay(1000);
//  motor1.run(BACKWARD);
//  delay(1000);
//  motor1.run(RELEASE);
//
//  motor2.run(RELEASE);
//  delay(3000);
//  motor2.run(FORWARD); // left
//  delay(2000);
//  motor2.run(RELEASE);
//  delay(1000);
//  motor2.run(BACKWARD); // right
//  delay(2000);
//  motor2.run(RELEASE);
}

void loop() {
//  if (Serial.available() > 0)
  {
    delay(100);
    int i=0;
    char cs[6];
    while (Serial.available() > 0)
    {
      cs[i] = Serial.read();
      i++;
    }
//    String cs[] = Serial.readline();
    char c1 = cs[0];
    char c2 = cs[1];
    if (c1 == 'l')
    {
      Serial.write('L');
      motor2.run(FORWARD);
    }
    else if (c1 == 'r')
    {
      Serial.write('R');
      motor2.run(BACKWARD);
    }
    else
    {
      Serial.write('S');
      motor2.run(RELEASE);
    }
    
    if (c2 == 'f')
    {
      Serial.write('F');
      motor1.run(FORWARD);
    }
    else if (c2 == 'b')
    {
      Serial.write('B');
      motor1.run(BACKWARD);
    }
    else
    {
      Serial.write('S');
      motor1.run(RELEASE);
    }
    Serial.write(' ');
    Serial.write(c1);
    Serial.write(c2);
    Serial.write(' ');
    Serial.write('\n');
  }
//  else
//  {
//    Serial.write('S');
//    Serial.write('S');
//    Serial.write('\n');
//  }
  
//  Serial.print('x');
//  char c = Serial.read();
//  Serial.println(c);
//  delay(1000);
  
  
// if (Serial.available() > 0)
// { 
//      char potato[] = "muta";
      
//    String potato = Serial.readStringUntil('\n');
//    Serial.print("Arduino: ");
//    Serial.println(potato);
//  }

//  motor.run(FORWARD);
//  delay(2000);
//  motor.run(RELEASE);
//  delay(1000);
}
