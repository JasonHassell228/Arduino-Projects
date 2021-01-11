#define ENA 9
#define IN1 3
#define IN2 4
#define ENB 10
#define IN3 5
#define IN4 6



void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT); /* This is the first motor */
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); /* This is the second mototr */

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  //analogWrite(ENA, 200);
  //analogWrite(ENB, 200);
  
  
  Serial.begin(9600);
  Serial.print("We're starting!\n");

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

void loop() {
  // put your main code here, to run repeatedly:
  moveForward();
  Serial.println("Just going forward!");

  delay(6000);

  Serial.println("Going in reverse!");
  moveBackward();

  delay(6000);

  Serial.println("OK!");


}
