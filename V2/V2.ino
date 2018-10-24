//V2: vertical prototype
//Goal: Allow a user to change the pitch of a buzzer using pushbuttons

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

const int keyC = 10;
const int keyD = 9;
const int keyE = 8;
const int keyF = 7;
const int keyG = 6;
const int keyA = 5;
const int keyB = 4;
const int highkeyC = 3;

const int buzzer = 11;

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
      tone(buzzer, C);
   }
   while(digitalRead(keyD) == LOW){
      tone(buzzer, D);
   }
   while(digitalRead(keyE) == LOW){
      tone(buzzer, E);
   }
   while(digitalRead(keyF) == LOW){
      tone(buzzer, F);
   }
   while(digitalRead(keyG) == LOW){
      tone(buzzer, G);
   }
   while(digitalRead(keyA) == LOW){
      tone(buzzer, A);
   }
   while(digitalRead(keyB) == LOW){
      tone(buzzer, B);
   }

   //If no button is being pressed, turns off the buzzer.
   noTone(buzzer);
   

}
