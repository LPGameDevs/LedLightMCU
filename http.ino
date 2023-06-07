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

  serverSetBrightness();
  serverSetColours();
  serverSetLights();

  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*"); 

  // Start server
  server.begin();
}

bool httpProcessJsonData(String json) {

  DeserializationError error = deserializeJson(doc, json);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  }

  return true;
}

void serverSetBrightness() {
  server.on("/brightness", HTTP_GET, [](AsyncWebServerRequest *request){
 
    int paramsNr = request->params();
    Serial.println(paramsNr);


    if (request->hasParam("q")) {
      String valueStr = request->getParam("q")->value();
      int brightness = valueStr.toInt();
      ledSetBrightness(brightness);
    }

 
    for(int i=0;i<paramsNr;i++){
 
        AsyncWebParameter* p = request->getParam(i);
        Serial.print("Param name: ");
        Serial.println(p->name());
        Serial.print("Param value: ");
        Serial.println(p->value());
        Serial.println("------");
    }
 
    request->send(200, "text/plain", "message received");
  });

 
}

void serverSetLights() {
  server.on("/set/light", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", "hello world");

    if (request->hasArg("body")) {
      String json = request->arg("body");

      bool success = httpProcessJsonData(json);
      if (success) {
        int light = doc["light"];
        int colour = doc["colour"];
        ledColorEnum colourEnum = static_cast<ledColorEnum>(colour);
        ledSetLightColour(light, colourEnum);
      }
    }
  });
}

void serverSetColours() {
  server.on("/set/lights", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", "hello world");
    if (request->hasArg("body")) {
      String json = request->arg("body");

      bool success = httpProcessJsonData(json);
      if (success) {
        int colour = doc["colour"];
        ledColorEnum colourEnum = static_cast<ledColorEnum>(colour);
        ledSetColour(colourEnum);
      }
    }
  });
}
