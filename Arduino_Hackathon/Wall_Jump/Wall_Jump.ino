/*
 * A short player jumping over a box animation on an 8x8 LED matrix
 */

#include "LedControl.h"

LedControl lc1 = LedControl(12,11,10,1);
byte wall[] = {
    B00000000, 
    B00000000, 
    B00000000, 
    B00000000, 
    B10000000, 
    B10000000, 
    B00000000, 
    B00000000
  };
byte player[] = {
    B00000000, 
    B00000000, 
    B00000000, 
    B00000000, 
    B00000000, 
    B00010000, 
    B00000000, 
    B00000000
  };
  
void setup() {
  // put your setup code here, to run once:
  lc1.shutdown(0,false);
  lc1.setIntensity(0, 1);
  lc1.clearDisplay(0);
  
  setGround();
}

void setGround()
{
  // Set Ground
  lc1.setRow(0, 6, 255);
}

void setWall()
{
  // Set Wall
  switch(wall[4])
  {
    // 128, 64 32, 16, 8, 4, 2, 1
    case 128:
      wall[4] = 1;
      break;
    case 64:
      wall[4] = 128;
      break;
    case 32:
      wall[4] = 64;
      break;
    case 16:
      wall[4] = 32;
      break;
    case 8:
      wall[4] = 16;
      break;
    case 4:
      wall[4] = 8;
      break;
    case 2:
      wall[4] = 4;
      break;
    case 1:
      wall[4] = 2;
      break;
  }
  wall[5] = wall[4];
  
  lc1.setRow(0, 4, wall[4]);
  lc1.setRow(0, 5, wall[5]);
}

void updatePlayer()
{
  lc1.setRow(0, 5, player[5]);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lc1.clearDisplay(0);
  setWall();
  //updatePlayer();
  setGround();
  delay(500);
}
