#include <Arduino.h>

#define BUZZ 15

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(BUZZ, HIGH);
  delay(5);
  digitalWrite(BUZZ, LOW);
  delay(5);
}