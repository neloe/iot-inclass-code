#include <Arduino.h>
#include "esp_wpa2.h"
#include <Wifi.h>
#include "super_secret.h"
#include <HTTPClient.h>

/*
#define AP_ID "username"
#define AP_PASS "oh hell no"
*/
#define SSID "mywifiname"

void setup() {
	Serial.begin(9600);
	Serial.println("Setup... oh I hope this works");
	WiFi.disconnect(true);
	WiFi.mode(WIFI_STA);
	esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)AP_ID, strlen(AP_ID));
	esp_wifi_sta_wpa2_ent_set_username((uint8_t *)AP_ID, strlen(AP_ID));
	esp_wifi_sta_wpa2_ent_set_password((uint8_t *)AP_PASS, strlen(AP_PASS));

	esp_wifi_sta_wpa2_ent_enable();

	WiFi.begin(SSID);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("Wifi connected");
	Serial.print("IP addr: ");
	Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED)
  {
	  HTTPClient http;
	  http.begin("https://api.weather.gov/");
	  int httpResponseCode = http.GET();
	  Serial.println(httpResponseCode);
	  Serial.println(http.getString());
  }
  delay(600000);
}
