
enum ledColorEnum {
  off = 0, red = 1, green = 2, blue = 3, purple = 4, plum = 5
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
