#include "FastLED.h"

#define NUM_LEDS 144
#define DATA_PIN 5
#define BRIGHTNESS  64

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  delay(50);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  // put your main code here, to run repeatedly:
  kerstboom();
}

void updateMatrix(int j[]) {
  for (int i = 0; i <= NUM_LEDS; i++) {
    if (j[i] == 1) {
      leds[i] = CRGB::Red;
    }
    else if (j[i] == 2) {
      leds[i] = CRGB::Green;
    }
    else if (j[i] == 3) {
      leds[i] = CRGB::Blue;
    }
    else if (j[i] == 4) {
      leds[i] = CRGB::Yellow;
    }
    else if (j[i] == 5) {
      leds[i] = CRGB::Cyan;
    }
    else if (j[i] == 6) {
      leds[i] = CRGB::Purple;
    }
    else if (j[i] == 7) {
      leds[i] = CRGB::Orange;
    }
    else if (j[i] == 8) {
      leds[i] = CRGB::Brown;
    }
    else if (j[i] == 9) {
      leds[i] = CRGB::White;
    }
    else if (j[i] == 0) {
      leds[i] = CRGB::Black;
    }
  }

  FastLED.show();
}

void kerstboom() {
  int kerstboom[NUM_LEDS] = {0, 0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 7, 2, 2, 4, 0, 0, 0, 0,
                             0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
                             0, 0, 0, 2, 2, 2, 2, 1, 7, 0, 0, 0,
                             0, 0, 0, 2, 4, 1, 6, 2, 2, 0, 0, 0,
                             0, 0, 0, 1, 6, 2, 2, 2, 2, 0, 0, 0,
                             0, 0, 6, 2, 2, 2, 4, 2, 2, 2, 0, 0,
                             0, 0, 2, 1, 6, 2, 2, 2, 2, 2, 0, 0,
                             0, 2, 7, 2, 2, 1, 6, 1, 2, 2, 2, 0,
                             0, 2, 2, 2, 2, 2, 2, 2, 6, 1, 6, 0,
                             2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2,
                             0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0
                            };
  int kerstboom2[NUM_LEDS] = {0, 0, 0, 0, 0, 7, 4, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 4, 2, 2, 7, 0, 0, 0, 0,
                              0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
                              0, 0, 0, 2, 2, 2, 2, 6, 4, 0, 0, 0,
                              0, 0, 0, 2, 7, 6, 1, 2, 2, 0, 0, 0,
                              0, 0, 0, 6, 1, 2, 2, 2, 2, 0, 0, 0,
                              0, 0, 1, 2, 2, 2, 7, 2, 2, 2, 0, 0,
                              0, 0, 2, 6, 1, 2, 2, 2, 2, 2, 0, 0,
                              0, 2, 4, 2, 2, 6, 1, 6, 2, 2, 2, 0,
                              0, 2, 2, 2, 2, 2, 2, 2, 1, 6, 1, 0,
                              2, 2, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2,
                              0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0
                             };
  updateMatrix(kerstboom);
  delay(500);
  updateMatrix(kerstboom2);
  delay(500);
}
