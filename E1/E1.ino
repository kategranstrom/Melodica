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

const int up = 1;
const int down = 0;

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
int duration[100] = {0};
int restDuration[100] = {0};
int rlength = 0;
int count = 0;
int lastNote = 0;
int jump = 0;

int volume = 1;

int startNote = 0;
int stopNote = 0;
int startRest = 0;
int stopRest = 0;


void setup() {
  //Serial.begin(57600);
  
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

  pinMode(up, INPUT);
  digitalWrite(up, HIGH);

  pinMode(down, INPUT);
  digitalWrite(down, HIGH);
  
  //pinMode(RP, INPUT);
  //digitalWrite(RP, HIGH);
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
    //Serial.print("Wind speed = ");
    //Serial.print((float)windSpeed);
    //Serial.println(" MPH");
    lastTime = millis();
    volume = (int)(windSpeed*0.6666);
     
    
  }
  //If the button is being pressed, plays the corresponding note
   if(digitalRead(keyC) == LOW){
      toneAC(C, volume);
      if (lastNote != C) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = C;
   }
   
   if(digitalRead(keyCs) == LOW){
      toneAC(Cs, volume);
      if (lastNote != Cs) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = Cs;
   }
   if(digitalRead(keyD) == LOW){
      toneAC( D, volume);
      if (lastNote != D) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = D;
   }
   if(digitalRead(keyDs) == LOW){
      toneAC( Ds, volume);
      if (lastNote != Ds) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = Ds;
   }
   if(digitalRead(keyE) == LOW){
      toneAC(E, volume);
      if (lastNote != E) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = E;
   }
   if(digitalRead(keyF) == LOW){
      toneAC( F,volume);
      if (lastNote != F) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = F;
   }
   if(digitalRead(keyFs) == LOW){
      toneAC( Fs,volume);
      if (lastNote != Fs) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = Fs;
   }
   if(digitalRead(keyG) == LOW){
      toneAC(G,volume);
      if (lastNote != G) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = G;
   }
   if(digitalRead(keyGs) == LOW){
      toneAC(Gs,volume);
      if (lastNote != Gs) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = Gs;
   }
   if(digitalRead(keyA) == LOW){
      toneAC(A, volume);
      if (lastNote != A) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = A;
   }
   if(digitalRead(keyAs) == LOW){
      toneAC(As, volume);
      if (lastNote != As) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = As;
   }
   if(digitalRead(keyB) == LOW){
      toneAC(B, volume);
      if (lastNote != B) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = B;
      
   }
   if(digitalRead(highkeyC) == LOW){
      toneAC(highC, volume);
      if (lastNote != highC) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = highC;
      
   }
      
   //If no button is being pressed, turns off the buzzer.
   if (digitalRead(keyC) == HIGH && digitalRead(keyCs) == HIGH && digitalRead(keyD) == HIGH && digitalRead(keyDs) == HIGH && digitalRead(keyE) == HIGH && digitalRead(keyF) == HIGH && digitalRead(keyFs) == HIGH && digitalRead(keyG) == HIGH && digitalRead(keyGs) == HIGH && digitalRead(keyA) == HIGH && digitalRead(keyAs) == HIGH && digitalRead(keyB) == HIGH && digitalRead(highkeyC) == HIGH){
      noToneAC();
      if(recording && lastNote){
        stopNote = millis();
        record[rlength] = lastNote;
        duration[rlength] = stopNote - startNote;
        restDuration[rlength++] = stopRest - startRest;
        startRest = millis();

      }
      lastNote = 0;
   }
 

   while(digitalRead(RP) == LOW) {
    delay(10);
    count += 10;
    //Serial.println(count);
   }
   //Serial.println(recording);
   if(count >= 10 && count < 1000 && recording == 0) {
    //Serial.println("start recording");
      recording = 1;
      //delay(200);
    count = 0;
   }

   if(count >= 10 && count < 1000 && recording == 1) {
     //Serial.println("stop recording");
     recording = 0;
     count = 0;
    //delay(1000);
   }

   if(count >= 1000 && count < 6000) {
    volume = 1;
    //Serial.println("playBack");
    for(int i = 0; i < rlength; i++) {
      toneAC(record[i], volume,duration[i]);
      noToneAC();
      delay(restDuration[i+1]);
    }
    count = 0;
   }

   if (digitalRead(up) == LOW) {
    //increase octave
    jump = 440;
    if (millis() - lastTime > 200 && C == 262) {
      C = 523;
      Cs = 554;
      D = 587;
      Ds = 622;
      E = 659;
      F = 699;
      Fs = 740;
      G = 784;
      Gs = 831;
      A = 880;
      As = 932;
      B = 988;
      highC = 1047;
      lastTime = millis();
    }
    if (millis() - lastTime > 200 && C == 131) {
      C = 262;
      Cs = 277;
      D = 294;
      Ds = 311;
      E = 330;
      F = 349;
      Fs = 370;
      G = 392;
      Gs = 415;
      A = 440;
      As = 466;
      B = 494;
      highC = 523; 
      lastTime = millis();    
    }
    
   }


   if (digitalRead(down) == LOW) {
    //decrease octave
    jump = -220;
    if (millis() - lastTime > 200 && C == 262) {
      C = 131;
      Cs = 139;
      D = 147;
      Ds = 156;
      E = 165;
      F = 175;
      Fs = 185;
      G = 196;
      Gs = 208;
      A = 220;
      As = 233;
      B = 247;
      highC = 262;
      lastTime = millis();
    }
    if (millis() - lastTime > 200 && C == 523) {
      C = 262;
      Cs = 277;
      D = 294;
      Ds = 311;
      E = 330;
      F = 349;
      Fs = 370;
      G = 392;
      Gs = 415;
      A = 440;
      As = 466;
      B = 494;
      highC = 523; 
      lastTime = millis();    
    }
  }

   if (count > 6000){
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
      noToneAC();
      count = 0;
 
  }
   
}
