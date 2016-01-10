//segments
const int a = 6;
const int b = 2;
const int c = 3;
const int d = 4;
const int e = 5;
const int f = A3; // 1
const int g = 7;
const int p = 8;
//digits
const int d4 = 12;
const int d3 = 11;
const int d2 = 10;
const int d1 = 9;

//other
const float WHEEL_CIRC = 22.5; // Front wheel circumference in cm.
const int NUM_GAPS = 20; // Number of gaps/windows on interrupter wheel.
//const int X = 100;
const int del = 4500;
int count = 0; // Number of time the photogate is broken.
int photo_state = 0;
int zero_hold = 0;
float dist = 0; // Distance traveled.

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(13, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  noInterrupts();
  dist = count * (WHEEL_CIRC / NUM_GAPS);
  dispDec(4);
  
  if (dist >= 50 && dist <= 850) {
    digitalWrite(A2, HIGH);
  } else {
    digitalWrite(A2, LOW);
  }
  
  if (dist >= 1000) {
    digitalWrite(A1, HIGH);
    displayNumber((dist - 1000));
  } else {
    digitalWrite(A1, LOW);
    displayNumber(dist);
  }
  
  if (digitalRead(13) == 1)
  {
    if (photo_state == 0) {
      count++;
      photo_state = 1;
    }
  } else {
    if (photo_state == 1) {
      photo_state = 0;
    }
  }
  
  if (analogRead(A0) == 0)
  {
    digitalWrite(A1, HIGH);
    zero_hold++;
    if (zero_hold >= 50) {  
      count = 0;
      dist = 0.0;
    }
  } else {
    digitalWrite(A1, LOW);
    zero_hold = 0;
  }
  
  Serial.print(dist);
  Serial.println(" cm");
}
