#include "ESPAsyncWebServer.h"

AsyncWebServer server(80);

void setupHttp() {

    server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("http request - lights off");
        request->send_P(200, "text/plain", "hello world");
        ledTestResponse(true);
    });


    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("http request - lights on");
        request->send_P(200, "text/plain", "hello world");
        ledTestResponse(false);
    });

    // Start server
    server.begin();
}
