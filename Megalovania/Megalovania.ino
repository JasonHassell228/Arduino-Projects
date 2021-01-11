#include "C:\Program Files (x86)\Arduino\libraries\pitches.h"
// Note frequencies for song: https://gist.github.com/zoomerbot101/e6dd9417799eea21bc47#file-megalovania_bass-ino

int speaker = 8;
bool on = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);

  //pong();
  //sans();
}

void play(int tone_freq)
{
  tone(speaker, tone_freq, 75);
}

void sans_intro(int d, int d2, int d3, int start_note)
{
  play(start_note);
  delay(d);
  play(start_note);
  delay(d);
  play(NOTE_D5);
  delay(d2);
  play(NOTE_A4);
  delay(d3);
  play(NOTE_GS4);
  delay(d2);
  play(NOTE_G4);
  delay(d2);
  play(NOTE_F4);
  delay(d2);
  play(NOTE_D4);
  delay(d);
  play(NOTE_F4);
  delay(d);
  play(NOTE_G4);
}

void sans()
{
  int d = 130;
  int d2 = d + 100;
  int d3 = d2 + 100;
  sans_intro(d, d2, d3, NOTE_D4);
  delay(d);
  sans_intro(d, d2, d3, NOTE_C4);
  delay(d);
  sans_intro(d, d2, d3, NOTE_B3);
  delay(d);
  sans_intro(d, d2, d3, NOTE_AS3);
  delay(d);
}

void pong()
{
  tone(speaker, 300, 100);
  delay(1500);
  tone(speaker, 200, 100);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (on)
  {
    
  }
  sans();
}
