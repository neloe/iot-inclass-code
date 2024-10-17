#include <ArduinoJson.h>

#define PACKETLEN 252
JsonDocument message;
char packet[PACKETLEN];

void setup() {
  // put your setup code here, to run once:
  message["id"] = 255;
  //message["loc"] = "somewhere";
  message["rs"] = JsonDocument();
  Serial.begin(9600);
  while(!Serial) delay(1);
  serializeJson(message, Serial);
  Serial.println();
  serializeMsgPack(message, Serial);
}

void loop() {
  message["rs"]["at"] = 18 + rand() % 6;
  message["rs"]["pH"] = 5 + (rand() % 20) / 2.0;
  message["rs"]["lt"] = 4095;
  int bytes = serializeJson(message, packet);
  //serializeJson(message, Serial);
  Serial.printf("%s: %d\n", packet, bytes);
  bytes = serializeMsgPack(message, packet);
  Serial.printf("%s: %d\n", packet, bytes);
  //serializeMsgPack(message, Serial);
  //Serial.println();
  delay(5000);
}
