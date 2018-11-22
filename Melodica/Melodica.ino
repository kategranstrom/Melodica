//Melodica
//Wind sensor calculations based on the program WindSensor.ino by Paul Badger:
//https://github.com/moderndevice/Wind_Sensor/blob/master/WindSensor/WindSensor.ino
#include <toneAC.h>

//these are the frequencies for each key on the piano
//our octave button is able to increase/decrease these
float C = 262;
float Cs = 277;
float D = 294;
float Ds = 311;
float E = 330;
float F = 349;
float Fs = 370;
float G = 392;
float Gs = 415;
float A = 440;
float As = 466;
float B = 494;
float highC = 523;

//the pins used by the arduino for each piano key
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

//buttons for octave up and octave down
const int up = 1;
const int down = 0;

//pins for our wind sensor
const int RP = 13;
const int RV = 5;
const int TMP = 4;

//these variables are used in the calculation of wind speed
long int lastTime;
float windSpeed;
float windOutput;
int tempOutput; 
float windVolts;
float windAdjustment = 0.2;
float zeroWindOutput;
float zeroWindVolts;

//keep track of when we are recording and hen we are not and store information on note name, note duration, 
//and duration of rest between notes
int recording = 0;
int record[100] = {0};
int duration[100] = {0};
int restDuration[100] = {0};
int rlength = 0;
int count = 0;
int lastNote = 0;
int startNote = 0;
int stopNote = 0;
int startRest = 0;
int stopRest = 0;

int volume = 0;

void setup() {
    
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
}
void loop() {
  // calculations for windspeed
  if (millis() - lastTime > 200) {
    tempOutput = analogRead(TMP);
    windOutput = analogRead(RV);
    windVolts = (windOutput * 0.0048828125);
    zeroWindOutput = -0.0006*(pow((float)tempOutput , 2)) + 1.0727*(float)tempOutput + 47.172;
    zeroWindVolts = (zeroWindOutput * 0.0048828125) - windAdjustment;
    windSpeed = pow(((windVolts-zeroWindVolts)/0.23), 2.7265);
    lastTime = millis();
    volume = (int)(windSpeed*0.6666);
  }
  
  //If the button is being pressed, plays the corresponding note
  //keep track of when the rest ends and note starts
   if(digitalRead(keyC) == LOW){
      toneAC(C, volume);
      if (lastNote != (int) C) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int) C;
   }
   
   if(digitalRead(keyCs) == LOW){
      toneAC(Cs, volume);
      if (lastNote != (int)Cs) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int) Cs;
   }
   if(digitalRead(keyD) == LOW){
      toneAC( D, volume);
      if (lastNote != (int) D) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)D;
   }
   if(digitalRead(keyDs) == LOW){
      toneAC( Ds, volume);
      if (lastNote != (int)Ds) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)Ds;
   }
   if(digitalRead(keyE) == LOW){
      toneAC(E, volume);
      if (lastNote != (int)E) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)E;
   }
   if(digitalRead(keyF) == LOW){
      toneAC( F,volume);
      if (lastNote != (int)F) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)F;
   }
   if(digitalRead(keyFs) == LOW){
      toneAC( Fs,volume);
      if (lastNote != (int)Fs) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)Fs;
   }
   if(digitalRead(keyG) == LOW){
      toneAC(G,volume);
      if (lastNote != (int)G) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)G;
   }
   if(digitalRead(keyGs) == LOW){
      toneAC(Gs,volume);
      if (lastNote != (int)Gs) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)Gs;
   }
   if(digitalRead(keyA) == LOW){
      toneAC(A, volume);
      if (lastNote != (int)A) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)A;
   }
   if(digitalRead(keyAs) == LOW){
      toneAC(As, volume);
      if (lastNote != (int)As) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)As;
   }
   if(digitalRead(keyB) == LOW){
      toneAC(B, volume);
      if (lastNote != (int)B) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)B;
      
   }
   if(digitalRead(highkeyC) == LOW){
      toneAC(highC, volume);
      if (lastNote != (int)highC) {
        stopRest = millis();
        startNote = millis();
      }
      lastNote = (int)highC;
      
   }
      
   //If no button is being pressed, turns off the buzzer.
   //keep track of stopping note and starting rest for the purpose of recording and playback
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
 
  //keep track of time a button is pressed for multifunction
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

  //if pressed for less than one second and not recording then start recording
   if(count >= 10 && count < 1000 && recording == 1) {
     //Serial.println("stop recording");
     recording = 0;
     count = 0;
    //delay(1000);
   }

  //if pressed for less than one second and recording then stop recording
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
    float exponent = 1.0/12;
    if (millis() - lastTime > 200 && C < 2000) {
      C = highC;
      Cs = C*pow(2, exponent);
      D = Cs*pow(2, exponent);
      Ds = D*pow(2, exponent);
      E = Ds*pow(2, exponent);
      F = E*pow(2, exponent);
      Fs = F*pow(2, exponent);
      G = Fs*pow(2, exponent);
      Gs = G*pow(2, exponent);
      A = Gs*pow(2, exponent);
      As = A*pow(2, exponent);
      B = As*pow(2, exponent);
      highC = 1047;
      lastTime = millis();
    }
   }


   if (digitalRead(down) == LOW) {
    //decrease octave
    float exponent = 1.0/12;
    if (millis() - lastTime > 200 && C > 20) {
      highC = C;
      B = highC/pow(2, exponent);
      As = B/pow(2, exponent);
      A = As/pow(2, exponent);
      Gs = A/pow(2, exponent);
      G = Gs/pow(2, exponent);
      Fs = G/pow(2, exponent);
      F = Fs/pow(2, exponent);
      E = F/pow(2, exponent);
      Ds = E/pow(2, exponent);
      D = Ds/pow(2, exponent);
      Cs = D/pow(2, exponent);
      C = Cs/pow(2, exponent);
      lastTime = millis();
    }
  }

  //special feature if button pressed for more than 6 seconds
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
