#include "ESPAsyncWebServer.h"

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

  // Start server
  server.begin();
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
