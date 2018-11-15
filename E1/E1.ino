//E1: evolutionary prototype
//Goal: Start integrating components to create our Melodica
//Wind sensor calculations based on the program WindSensor.ino by Paul Badger:
//https://github.com/moderndevice/Wind_Sensor/blob/master/WindSensor/WindSensor.ino
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

const int keyC = 12;
const int keyCs = 11;
const int keyD = 8;
const int keyDs = 7;
const int keyE = 6;
const int keyF = 5;
const int keyFs = 4;
const int keyG = 3;
const int keyGs = 2;
const int keyA = 14;
const int keyAs = 15;
const int keyB = 16;
const int highkeyC = 17;

const int RV = 5;
const int TMP = 4;
long int lastTime;
float windSpeed;
float windOutput;
int tempOutput; 
float windVolts;
float windAdjustment = 0.2;
float zeroWindOutput;
float zeroWindVolts;



int volume = 1;

void setup() {

  Serial.begin(57600);
  
  //sets up the pins that connect our pushbuttons
  
  pinMode(keyC, INPUT);
  digitalWrite(keyC, HIGH);

  pinMode(keyCs, INPUT);
  digitalWrite(keyCs, HIGH);

  pinMode(keyD, INPUT);
  digitalWrite(keyD, HIGH);

  pinMode(keyDs, INPUT);
  digitalWrite(keyDs, HIGH);

  pinMode(keyE, INPUT);
  digitalWrite(keyE, HIGH);

  pinMode(keyF, INPUT);
  digitalWrite(keyF, HIGH);

  pinMode(keyFs, INPUT);
  digitalWrite(keyFs, HIGH);

  pinMode(keyG, INPUT);
  digitalWrite(keyG, HIGH);

  pinMode(keyGs, INPUT);
  digitalWrite(keyGs, HIGH);

  pinMode(keyA, INPUT);
  digitalWrite(keyA, HIGH);

  pinMode(keyAs, INPUT);
  digitalWrite(keyAs, HIGH);

  pinMode(keyB, INPUT);
  digitalWrite(keyB, HIGH);

  pinMode(highkeyC, INPUT);
  digitalWrite(highkeyC, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - lastTime > 200) {
    tempOutput = analogRead(TMP);
    windOutput = analogRead(RV);
    windVolts = (windOutput * 0.0048828125);

    zeroWindOutput = -0.0006*(pow((float)tempOutput , 2)) + 1.0727*(float)tempOutput + 47.172;
    zeroWindVolts = (zeroWindOutput * 0.0048828125) - windAdjustment;

    windSpeed = pow(((windVolts-zeroWindVolts)/0.23), 2.7265);

    Serial.print("Wind speed = ");
    Serial.print((float)windSpeed);
    Serial.println(" MPH");
    lastTime = millis();
  }
  //If the button is being pressed, plays the corresponding note
   while(digitalRead(keyC) == LOW){
      toneAC(C, volume);
   }
   while(digitalRead(keyCs) == LOW){
      toneAC(Cs, volume);
   }
   while(digitalRead(keyD) == LOW){
      toneAC( D, volume);
   }
   while(digitalRead(keyDs) == LOW){
      toneAC( Ds, volume);
   }
   while(digitalRead(keyE) == LOW){
      toneAC(E, volume);
   }
   while(digitalRead(keyF) == LOW){
      toneAC( F,volume);
   }
   while(digitalRead(keyFs) == LOW){
      toneAC( Fs,volume);
   }
   while(digitalRead(keyG) == LOW){
      toneAC(G,volume);
   }
   while(digitalRead(keyGs) == LOW){
      toneAC(Gs,volume);
   }
   while(digitalRead(keyA) == LOW){
      toneAC(A, volume);
   }
   while(digitalRead(keyAs) == LOW){
      toneAC(As, volume);
   }
   while(digitalRead(keyB) == LOW){
      toneAC(B, volume);
      
   }
   while(digitalRead(highkeyC) == LOW){
      toneAC(highC, volume);
      
   }
   
   //If no button is being pressed, turns off the buzzer.
   noToneAC();

}

