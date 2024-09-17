#include <Wire.h>
#include <Adafruit_AHTX0.h>

TwoWire i2c;
Adafruit_AHTX0 aht;

#define SCL_PIN 7
#define SDA_PIN 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!i2c.begin(, 9))
  {
    Serial.println("I2C is not initializing");
    while(1);
  }
  if (!aht.begin(&i2c))
  {
    Serial.println("AHHHHHHHHHHHH");
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t humidity, temperature;
  aht.getEvent(&humidity, &temperature);

  Serial.print("Temperature: ");
  Serial.print(temperature.temperature);
  Serial.println(" deg C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %rH");
  Serial.println("----");
  delay(1000);

}
