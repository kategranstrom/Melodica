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

const int RP = 13;

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


int recording = 0;
int record[100] = {0};
int rlength = 0;
int count = 0;

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

  pinMode(RP, INPUT);
  digitalWrite(RP, HIGH);


}



void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - lastTime > 1) {
    tempOutput = analogRead(TMP);
    windOutput = analogRead(RV);
    windVolts = (windOutput * 0.0048828125);

    zeroWindOutput = -0.0006*(pow((float)tempOutput , 2)) + 1.0727*(float)tempOutput + 47.172;
    zeroWindVolts = (zeroWindOutput * 0.0048828125) - windAdjustment;

    windSpeed = pow(((windVolts-zeroWindVolts)/0.23), 2.7265);

    //Serial.print("Wind speed = ");
    //Serial.print((float)windSpeed);
    //Serial.println(" MPH");
    lastTime = millis();
    volume = (int)(windSpeed*0.6666);
     
    
  }
  //If the button is being pressed, plays the corresponding note
  if (digitalRead(RP) == LOW){
      volume = 1;
      toneAC(C, volume);
      delay(150);
      toneAC(D, volume);
      delay(150);
      toneAC(F, volume);
      delay(150);
      toneAC(D, volume);
      delay(150);
      toneAC(A, volume);
      delay(450);
      noToneAC();
      delay(25);
      toneAC(A, volume);
      delay(450);
      toneAC(G, volume);
      delay(900);
      toneAC(C, volume);
      delay(150);
      toneAC(D, volume);
      delay(150);
      toneAC(F, volume);
      delay(150);
      toneAC(D, volume);
      delay(150);
      toneAC(G, volume);
      delay(450);
      noToneAC();
      delay(25);
      toneAC(G, volume);
      delay(450);
      toneAC(F, volume);
      delay(450);
      toneAC(E, volume);
      delay(150);
      toneAC(D, volume);
      delay(300);
      toneAC(C, volume);
      delay(150);
      toneAC(D, volume);
      delay(150);
      toneAC(F, volume);
      delay(150);
      toneAC(D, volume);
      delay(150);
      toneAC(F, volume);
      delay(600);
      toneAC(G, volume);
      delay(300);
      toneAC(E, volume);
      delay(450);

      toneAC(D, volume);
      delay(150);
      toneAC(C, volume);
      delay(300);
      toneAC(C, volume);
      delay(300);
      noToneAC();
      delay(25);
      toneAC(C, volume);
      delay(300);
      toneAC(G, volume);
      delay(600);
      toneAC(F, volume);
      delay(1200);
 
  }
  
   if(digitalRead(keyC) == LOW){
      toneAC(C, volume);
      if(record) record[rlength++] = C;
   }
   
   if(digitalRead(keyCs) == LOW){
      toneAC(Cs, volume);
      if(record) record[rlength++] = Cs;
   }
   if(digitalRead(keyD) == LOW){
      toneAC( D, volume);
      if(record) record[rlength++] = D;
   }
   if(digitalRead(keyDs) == LOW){
      toneAC( Ds, volume);
      if(record) record[rlength++] = Ds;
   }
   if(digitalRead(keyE) == LOW){
      toneAC(E, volume);
      if(record) record[rlength++] = E;
   }
   if(digitalRead(keyF) == LOW){
      toneAC( F,volume);
      if(record) record[rlength++] = F;
   }
   if(digitalRead(keyFs) == LOW){
      toneAC( Fs,volume);
      if(record) record[rlength++] = Fs;
   }
   if(digitalRead(keyG) == LOW){
      toneAC(G,volume);
      if(record) record[rlength++] = G;
   }
   if(digitalRead(keyGs) == LOW){
      toneAC(Gs,volume);
      if(record) record[rlength++] = Gs;
   }
   if(digitalRead(keyA) == LOW){
      toneAC(A, volume);
      if(record) record[rlength++] = A;
   }
   if(digitalRead(keyAs) == LOW){
      toneAC(As, volume);
      if(record) record[rlength++] = As;
   }
   if(digitalRead(keyB) == LOW){
      toneAC(B, volume);
      if(record) record[rlength++] = B;
      
   }
   if(digitalRead(highkeyC) == LOW){
      toneAC(highC, volume);
      if(record) record[rlength++] = highC;
      
   }
   while(digitalRead(RP) == LOW) {
    delay(100);
    count += 100;
    Serial.println(count);
   }
   
   if(count >= 100 && !recording) {
    if(!recording) {
    Serial.println("start recording");
      recording = 1;
      //delay(200);
    }
    count = 0;
   }
   
   if(count >= 100 && recording) {
     Serial.println("stop recording");
     if(recording) {
       recording = 0;
     }
    count = 0;
    //delay(1000);
   }
   
   //If no button is being pressed, turns off the buzzer.
   if (digitalRead(keyC) == HIGH && digitalRead(keyCs) == HIGH && digitalRead(keyD) == HIGH && digitalRead(keyDs) == HIGH && digitalRead(keyE) == HIGH && digitalRead(keyF) == HIGH && digitalRead(keyFs) == HIGH && digitalRead(keyG) == HIGH && digitalRead(keyGs) == HIGH && digitalRead(keyA) == HIGH && digitalRead(keyAs) == HIGH && digitalRead(keyB) == HIGH && digitalRead(highkeyC) == HIGH){
      noToneAC();
   }
   

}
