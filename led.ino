/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <FastLED.h>

#define NUM_LEDS 30

CRGB leds[NUM_LEDS];

const int ledPin = 4; //marked as D2 on the board

bool inverse = false;
bool _override = true;

void setupLed()
{
    FastLED.addLeds<WS2812B, ledPin, RGB>(leds, NUM_LEDS);
}

void loopLed()
{
    // Debug delay.
    delay(100);

    if (!_override) {
        ledLoopAmbientLight();
    }

    FastLED.show();
}

void ledTurnOffAll() {
    _override = true;

    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(100, 100, 0);
    }

    Serial.println("led - lights off");
}

void ledTurnOnAll() {
    _override = false;

    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(100, 100, 100);
    }

    Serial.println("led - lights on");
}

void ledLoopAmbientLight() {
    unsigned long currentMillis = millis();
    float offset = 250;
    float totalOffset = offset * NUM_LEDS;

    int intervals = std::floor(currentMillis / totalOffset);
    inverse = ( intervals % 2 == 0);

    // Restart the loop.
    while (currentMillis > totalOffset) {
        currentMillis = currentMillis - totalOffset;
    }

    float progress = (float) currentMillis / totalOffset;
    if (inverse) {
        progress = (float) (totalOffset - currentMillis) / totalOffset;
    }

    float hue = progress * 255;
    float brightness = progress * 100;
    float three = progress * 255;

    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV (hue + (i * 5), 255, brightness + 100);
    }
}
