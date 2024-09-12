#define BLUE_LED_PIN 9
int brightness = 0;
void toggleBlue();
bool blue_is_on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //toggleBlue();
  analogWrite(BLUE_LED_PIN, brightness);
  delay(1000);
  brightness *= 2;
  brightness += 1;
  if (brightness > 127) brightness = 0;
}

void toggleBlue()
{
  digitalWrite(BLUE_LED_PIN, blue_is_on);
  blue_is_on = !blue_is_on;
}