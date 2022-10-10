#include <Arduino.h>
#include <Display.h>
const int button = 9;
const int led = 4;
const int potmeter = A0;
float a;
int b;
int c;
int d;
int e;
void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(potmeter, INPUT);
  a = analogRead(potmeter);
  a = (a + 53);
  a = (a * 73);
  a = (a * a);
  a = (a / 3);
  while (a > 20000)
  {
    a = a / 10;
  }
  if (a < 0)
  {
    a = a * -1;
  }
}

void loop()
{
  b = a;
  c = millis();
  d = digitalRead(button);
  Display.show(c / 10);
  if (c >= b)
  {
    digitalWrite(led, HIGH);
  }
  if (d == LOW)
  {
    Display.show(c - b);
    while (1)
    {
    }
  }
  Serial.println(b);
}