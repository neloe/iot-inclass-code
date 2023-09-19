#include <Arduino.h>
#include <U8g2lib.h>

//boilerplate because I said so
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

typedef U8G2_SSD1306_128X64_NONAME_F_SW_I2C SeeedDisplay;

SeeedDisplay oled(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  oled.begin();
}

void loop() {
  oled.clearBuffer();
  oled.setFont(u8g2_font_luBIS08_tf);
  oled.drawStr(0,10, "Hi world!");
  oled.sendBuffer();
  delay(100);
  oled.drawStr(0,30, String(5).c_str());
  oled.sendBuffer();
  delay(100);
  oled.drawStr(0,50, "neat");
  oled.sendBuffer();
}
