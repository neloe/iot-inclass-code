#include <Arduino.h>
#include <FastLED.h>

CRGB led[1];

#define LED_PIN 5

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led, 1);
  led[0] = CRGB::Purple;
  FastLED.show();
  Serial.begin(9600);
  Serial.println("Hello world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  led[0] = CRGB::Black;
  FastLED.show();
  delay(1);
  led[0] = CRGB::Purple;
  FastLED.show();
  delay(3);
  Serial.println(CRGB::Purple);
}