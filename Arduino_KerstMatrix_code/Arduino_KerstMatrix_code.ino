#include "FastLED.h"

#define NUM_LEDS 144

#define DATA_PIN 5

#define BRIGHTNESS  64

CRGB leds[NUM_LEDS];

int bitMap[NUM_LEDS] = {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                        1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       };

void setup() {
  delay(2000);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  updateMatrix();
}

void updateMatrix() {
  for (int i = 0; i <= NUM_LEDS; i++) {
    if (bitMap[i] == 1) {
      leds[i] = CRGB::Red;
    }
    else if (bitMap[i] == 2) {
      leds[i] = CRGB::Green;
    }
    else if (bitMap[i] == 3) {
      leds[i] = CRGB::Blue;
    }
    else if (bitMap[i] == 4) {
      leds[i] = CRGB::Yellow;
    }
    else if (bitMap[i] == 5) {
      leds[i] = CRGB::Cyan;
    }
    else if (bitMap[i] == 6) {
      leds[i] = CRGB::Purple;
    }
    else if (bitMap[i] == 7) {
      leds[i] = CRGB::Orange;
    }
    else if (bitMap[i] == 8) {
      leds[i] = CRGB::Brown;
    }
    else if (bitMap[i] == 9) {
      leds[i] = CRGB::White;
    }
    else if (bitMap[i] == 0) {
      leds[i] = CRGB::Black;
    }
  }

  FastLED.show();
}
