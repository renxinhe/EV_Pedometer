//segments
const int a = 6;
const int b = 2;
const int c = 3;
const int d = 4;
const int e = 5;
const int f = 1;
const int g = 7;
const int p = 8;
//digits
const int d4 = 9;
const int d3 = 10;
const int d2 = 11;
const int d1 = 12;

//other
int n = 0;
const int x = 100;
const int del = 25;
int photo_state = 0;

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
  Serial.begin(9600);
}

void loop()
{
  displayNumber(n / x);

  if (digitalRead(13) == 1)
  {
    if (photo_state == 0) {
      n++;
      photo_state = 1;
    }
  } else {
    if (photo_state == 1) {
      photo_state = 0;
    }
  }

  Serial.println(n);
}
