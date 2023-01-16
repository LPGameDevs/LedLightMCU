#include "ESPAsyncWebServer.h"

AsyncWebServer server(80);

void setupHttp() {

    server.on("/test", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("http request");
        request->send_P(200, "text/plain", "hello world");
        ledTestResponse();
    });

    // Start server
    server.begin();
}
