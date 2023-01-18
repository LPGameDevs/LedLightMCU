#include "ESPAsyncWebServer.h"
#include <ArduinoJson.h>

StaticJsonDocument<200> doc;

AsyncWebServer server(80);

void setupHttp() {

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights off");
    request->send_P(200, "text/plain", "hello world");
    ledTestResponse(true);
  });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights on");
    request->send_P(200, "text/plain", "hello world");
    ledTestResponse(false);
  });

  serverSetColours();
  serverSetLights();

  // Start server
  server.begin();
}

void serverSetLights() {
  server.on("/set/light", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", "hello world");

    if (request->hasArg("body")) {
      String json = request->arg("body");
      DeserializationError error = deserializeJson(doc, json);

      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }

      int light = doc["light"];
      int colour = doc["colour"];
      ledColorEnum colourEnum = static_cast<ledColorEnum>(colour);

      Serial.println(light);
      Serial.println(colour);
      Serial.println(colourEnum);

      ledSetLightColour(light, colourEnum);
    }
  });
}

void serverSetColours() {

  server.on("/set/red", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights to red");
    request->send_P(200, "text/plain", "hello world");
    ledSetColour(ledColorEnum::red);
  });

  server.on("/set/blue", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights to blue");
    request->send_P(200, "text/plain", "hello world");
    ledSetColour(ledColorEnum::blue);
  });

  server.on("/set/green", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights to green");
    request->send_P(200, "text/plain", "hello world");
    ledSetColour(ledColorEnum::green);
  });


  server.on("/set/purple", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights to purple");
    request->send_P(200, "text/plain", "hello world");
    ledSetColour(ledColorEnum::purple);
  });


  server.on("/set/plum", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("http request - lights to plum");
    request->send_P(200, "text/plain", "hello world");
    ledSetColour(ledColorEnum::plum);
  });
}
