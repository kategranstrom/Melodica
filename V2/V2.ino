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
int C = 523;

int keyC = 10;
int keyD = 9;
int keyE = 8;
int keyF = 7;
int keyG = 6;
int keyA = 5;
int keyB = 4;
int highkeyC = 3;

int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //If the button is being pressed, places the corresponding note
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
