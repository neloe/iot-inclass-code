#include <Arduino.h>

#define BTN 15

bool pushed = false;
unsigned long last_pushed = 0;

void IRAM_ATTR interrupt1();

void setup() {
  pinMode(BTN, INPUT_PULLDOWN);
  attachInterrupt(BTN, interrupt1, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pushed)
  {
    Serial.println("Pushed");
    pushed = false;
  }
  delay(100);
}

void IRAM_ATTR interrupt1()
{
  if (millis() - last_pushed > 200)
  {
    pushed = true;
    last_pushed=millis();
  }
  
}