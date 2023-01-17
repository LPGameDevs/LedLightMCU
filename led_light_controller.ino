
enum ledColorEnum {
  red, green, blue, purple, plum
};

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

void ledTestResponse(bool turnOff) {
  if (turnOff) {
    ledTurnOffAll();
  } else {
    ledTurnOnAll();
  }
}
