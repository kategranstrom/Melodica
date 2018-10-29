//V1: vertical prototype
//Goal: Change the volume of the buzzer using software
#include <toneAC.h>

//Maintaining the ability to change frequencies for our octave button
int C = 262;
int Cs = 277;
int D = 294;
int Ds = 311;
int E = 330;
int F = 349;
int Fs = 370;
int G = 392;
int Gs = 415;
int A = 440;
int As = 466;
int B = 494;
int highC = 523;

const int keyC = 8;
const int keyD = 7;
const int keyE = 6;
const int keyF = 5;
const int keyG = 4;
const int keyA = 3;
const int keyB = 2;
const int highkeyC = 1;

//const int buzzer = 11;

void setup() {
  //sets up the pins that connect our pushbuttons
  
  
  pinMode(keyC, INPUT);
  digitalWrite(keyC, HIGH);

  pinMode(keyD, INPUT);
  digitalWrite(keyD, HIGH);

  pinMode(keyE, INPUT);
  digitalWrite(keyE, HIGH);

  pinMode(keyF, INPUT);
  digitalWrite(keyF, HIGH);

  pinMode(keyG, INPUT);
  digitalWrite(keyG, HIGH);

  pinMode(keyA, INPUT);
  digitalWrite(keyA, HIGH);

  pinMode(keyB, INPUT);
  digitalWrite(keyB, HIGH);

  pinMode(highkeyC, INPUT);
  digitalWrite(highkeyC, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //If the button is being pressed, plays the corresponding note
   while(digitalRead(keyC) == LOW){
      toneAC(C, 1);
   }
   while(digitalRead(keyD) == LOW){
      toneAC( D, 3);
   }
   while(digitalRead(keyE) == LOW){
      toneAC(E, 4);
   }
   while(digitalRead(keyF) == LOW){
      toneAC( F,6);
   }
   while(digitalRead(keyG) == LOW){
      toneAC(G,7);
   }
   while(digitalRead(keyA) == LOW){
      toneAC(A, 9);
   }
   while(digitalRead(keyB) == LOW){
      toneAC(B, 10);
      
   }

   //If no button is being pressed, turns off the buzzer.
   noToneAC();
   

}
