#include <SPI.h>
#include <Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int previ = 0;
int maxi = 0;


int forwards = 8;
int backwards = 9;
int left = 10;
int right = 11;

int gyroSens = 4000;
int f = 0;
int fc = 0;
int b = 0;
int bc = 0;
int l = 0;
int lc = 0;
int r = 0;
int rc = 0;

char prev1;
char prev2;
char cur1;
char cur2;
int send1 = 0;
int send2 = 0;

void setup() {
  // Normal shit
  Serial.begin(9600);
  pinMode(forwards, INPUT);
  pinMode(backwards, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);

  pinMode(8, INPUT);
  pinMode(10, INPUT);

  // Gyro
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

//  while(true)
//  {
//    if(Serial.available() > 0)
//    {
//      if(Serial.read() == 'q')
//      {
//        Serial.write('g');
//        break;
//      }
//    }
//  }
}

void loop() {
//    f = analogRead(A0);
//    b = analogRead(A1);
//    r = analogRead(A2);
//    l = analogRead(A3);

//    Serial.print(f);
//  Serial.print("    ");
//  Serial.print(b);

//  Serial.print(f);
//  Serial.print("    ");
//  Serial.print(b);
//  Serial.print("    ");
//  Serial.print(l);
//  Serial.print("    ");
//  Serial.print(r);
//  Serial.print("\n");

//  if (l < 195 && r > 860)
//  {
//    Serial.print("f"); // forward
//  }
//  if (l > 860 && r < 180)
//  {
//    Serial.write("b"); // backward
//  }
//  if (f < 186 && b > 866)
//  {
//    Serial.write("r"); // right
//  }
//  if (f > 860 && b < 178)
//  {
//    Serial.write("l"); // left
//  }



  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)



  int pin1 = digitalRead(8);
  int pin2 = digitalRead(10);
  
  if (!pin1)
  {
    cur1 = 'f';
  }
  else if (!pin2)
  {
    cur1 = 'b';
  }
  else
  {
    cur1 = 's';
  }
  // left & right
  // old
//  if (AcX > gyroSens)
//  {
//    cur2 =  'l';
//  }
//  else if (AcX < -gyroSens)
//  {
//    cur2 = 'r';
//  }
//  else
//  {
//    cur2 = 's';
//  }
  // new
  Serial.write(cur1);
  Serial.write(" ");
  Serial.println(AcX);
  
//  if(cur1 != prev1){
//    send1 = 1;
//    prev1 = cur1;
//  } else  {
//    send1 = 0;
//  }
//
//  if(cur2 != prev2){
//    send2 = 1;
//    prev2 = cur2;
//  } else {
//    send2 = 0;
//  }
//
//  if(send1 == 1 || send2 == 1){
//    Serial.write(cur1);
//    Serial.write(cur2);
//    Serial.write("\n");
//  }
//  Serial.print(pin1);
//  Serial.print(pin2);
//  Serial.println();

//delay(200);
}
