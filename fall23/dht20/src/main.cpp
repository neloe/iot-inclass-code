#include <Arduino.h>
#include <Adafruit_AHTX0.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

Adafruit_AHTX0 aht;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
sensors_event_t temperature, humidity;
void setup() {
  Serial.begin(9600);
  Serial.println("I don't know what this will look like");
  if (!aht.begin())
  {
    Serial.println("AHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
    while(true) delay(10);
  }
  oled.begin();
  Serial.println("Init done");
}

void loop() {
  aht.getEvent(&humidity, &temperature);
  Serial.print("Temperature: ");
  Serial.println(temperature.temperature);
  Serial.print("Relative Humidity: ");
  Serial.println(humidity.relative_humidity);
  oled.clearBuffer();
  oled.setFont(u8g2_font_luBIS08_tf);
  oled.drawStr(0,30, "T:");
  oled.drawStr(20, 30, String(temperature.temperature).c_str());
  oled.drawStr(0, 50, "rH: ");
  oled.drawStr(40, 50, String(humidity.relative_humidity).c_str());
  oled.sendBuffer();
  delay(500);
}

