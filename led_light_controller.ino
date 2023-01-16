void setup() {
    // Serial port for debugging purposes
    Serial.begin(115200);
  
    setupWifi();
    setupHttp();
    setupLed();
}

void loop() {
    loopLed();
}

void ledTestResponse() {
  ledTurnOffAll();
}

