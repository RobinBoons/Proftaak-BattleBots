#include "FastLED.h"

#define NUM_LEDS 144

#define DATA_PIN 5

#define BRIGHTNESS  64

CRGB leds[NUM_LEDS];
int bitMap[NUM_LEDS] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                        9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 4, 7,
                       };

void setup() {
  delay(2000);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
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
  /*
    delay(75);

    // Turn our current led back to black for the next loop around
    for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    }

    FastLED.show();
    delay(75);
  */
}
