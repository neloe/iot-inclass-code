#include <Arduino.h>

#define BTN1 15

void do_button_thing();

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  do_button_thing();
  delay(500);
}

void do_button_thing()
{
  static int last_state = 1;
  static bool is_on = false;
  int btn_state = digitalRead(BTN1);
  if (last_state == 1 && btn_state == 0)
  {
    is_on = !is_on;
  }
  if (is_on)
  {
    Serial.println("ON");
  }
  else{
    Serial.println("OFF");
  }
  last_state = btn_state;
}
