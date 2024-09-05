#define BLUE_LED_PIN 9

void toggleBlue();
bool blue_is_on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  toggleBlue();
  delay(500);
}

void toggleBlue()
{
  digitalWrite(BLUE_LED_PIN, blue_is_on);
  blue_is_on = !blue_is_on;
}