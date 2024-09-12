#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!aht.begin())
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
