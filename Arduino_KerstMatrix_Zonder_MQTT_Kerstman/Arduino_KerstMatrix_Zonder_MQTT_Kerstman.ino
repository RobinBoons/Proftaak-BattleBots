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
  kerstman();
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
      leds[i] = CRGB::Grey;
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

void kerstman() {
  int kerstman[NUM_LEDS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 6, 0,
                            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 9, 6,
                            0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0,
                            0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
                            0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
                            0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0,
                            0, 0, 0, 8, 3, 8, 8, 3, 8, 0, 0, 0,
                            0, 0, 8, 8, 3, 8, 8, 3, 8, 8, 0, 0,
                            0, 0, 9, 8, 8, 8, 8, 8, 8, 9, 0, 0,
                            0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0,
                            0, 0, 9, 9, 8, 7, 4, 8, 9, 9, 0, 0,
                            0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0
                           };
  int kerstman2[NUM_LEDS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 9, 0,
                             0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 6, 9,
                             0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 9, 0,
                             0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
                             0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
                             0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0,
                             0, 0, 0, 8, 3, 8, 8, 8, 8, 0, 0, 0,
                             0, 0, 8, 8, 3, 8, 8, 3, 3, 8, 0, 0,
                             0, 0, 9, 8, 8, 8, 8, 8, 8, 9, 0, 0,
                             0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0,
                             0, 0, 9, 9, 8, 4, 7, 8, 9, 9, 0, 0,
                             0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0
                            };
  updateMatrix(kerstman);
  delay(500);
  updateMatrix(kerstman2);
  delay(500);
}

