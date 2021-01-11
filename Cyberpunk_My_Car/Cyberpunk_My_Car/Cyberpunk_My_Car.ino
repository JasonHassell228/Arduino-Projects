#include <TM1637.h>
#include <virtuabotixRTC.h>

int CLK = 51;
int DIO = 53;
int pointVal = 0;
int A = 46; // AM/PM

virtuabotixRTC myRTC(48, 50, 52);
TM1637 tm(CLK, DIO);

void setup() {
//  Serial.begin(9600);
  // Seconds, minutes, hours, day of week, day of month, month, year
  // This set the original time, don't uncomment this unless resyncing the time
  // Always upload a version of this code with the line commented, otherwise 
  // when the arduino turns on it'll reset the time again
//  myRTC.setDS1302Time(10, 55, 11, 1, 11, 1, 2021);
  tm.init();
  tm.set(2); // Brightness from 0-7
  pinMode(A, OUTPUT);
}

void displayNumber(int num){   
    tm.display(3, num % 10);
    tm.display(2, num / 10 % 10);
    tm.display(1, num / 100 % 10);
    tm.display(0, num / 1000 % 10);
}

void togglePoint(TM1637 *tm, int *pointVal) {
  if (*pointVal) {
    *pointVal = 0;
  } else {
    *pointVal = 1;
  }
}

void loop() {
  // RTC
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();
  // Start printing elements as individuals
//  Serial.print("Current Date / Time: ");
//  Serial.print(myRTC.dayofweek); // 0-6, starting at 0 on Sunday
//  Serial.print(", ");
//  Serial.print(myRTC.dayofmonth);
//  Serial.print("/");
//  Serial.print(myRTC.month);
//  Serial.print("/");
//  Serial.print(myRTC.year);
//  Serial.print("  ");
//  Serial.print(myRTC.hours);
//  Serial.print(":");
//  Serial.print(myRTC.minutes);
//  Serial.print(":");
//  Serial.println(myRTC.seconds);

  // DISPLAY
  // example: "12:ab"
  // tm.display(position, character);
  // tm.display(0, 1); (1, 2); (2, 10); (3, 11); etc.
  // tm.point(1) for middle dots on, (0) for dots off

  int clockTime = 0;
  if (myRTC.hours < 12) {
    clockTime = myRTC.hours;
    clockTime *= 100;
    clockTime += myRTC.minutes;
    digitalWrite(A, 1); // AM
//    Serial.println("am");
  } else {
    if (myRTC.hours == 12) {
      clockTime = myRTC.hours;
    } else {
      clockTime = myRTC.hours - 12;
    }
    clockTime *= 100;
    clockTime += myRTC.minutes;
    digitalWrite(A, 0); // PM
//    Serial.println("pm");
  }
//  Serial.println(clockTime);
  togglePoint(&tm, &pointVal);
  tm.point(pointVal);
  displayNumber(clockTime);

  // Delay so the program doesn't print non-stop
  delay(1000);
}
