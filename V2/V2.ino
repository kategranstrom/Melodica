

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

}
