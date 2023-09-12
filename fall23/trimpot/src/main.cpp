#include <Arduino.h>

#define VIN 36

void setup() {
  pinMode(VIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vin = analogReadMilliVolts(VIN);
  Serial.println(vin);
  delay(50);
}