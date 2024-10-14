#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_SSD1306.h>

#define SDA_PIN 7
#define SCL_PIN 9

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3c

Adafruit_AHTX0 aht;
TwoWire i2c(0);
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &i2c, OLED_RESET);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!i2c.begin(SDA_PIN, SCL_PIN))
  {
    Serial.println("I2c not init'd");
    while(1);
  }
  if (!oled.begin())
  {
    Serial.println("oled go boom");
    while(1);
  }
  if (!aht.begin(&i2c))
  {
    Serial.println("AHHHHHHHHHHHH");
    while(1);
  }
  oled.display();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t humidity, temperature;
  aht.getEvent(&humidity, &temperature);
  /*
  Serial.print("Temperature: ");
  Serial.print(temperature.temperature);
  Serial.println(" deg C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %rH");
  Serial.println("----");*/
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.printf("Temperature: %.2f deg F\n", temperature.temperature*9.0/5+32);
  oled.printf("Humidity: %.2f %%rH", humidity.relative_humidity);
  oled.display();
  delay(1000);

}

