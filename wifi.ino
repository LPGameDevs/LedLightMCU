// Import required libraries
#include <ESP8266WiFi.h>
#include "WiFiCredentials.h"

//const char* ssid = "home";
//const char* password = "password";

void setupWifi() {

  Serial.println();

  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.mode(WIFI_STA);


  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
