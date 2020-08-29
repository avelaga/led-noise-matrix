#include <FastLED.h>

#define NUM_LEDS 20
#define NUM_STRIPS 4
#define SCALE 50

CRGB leds[NUM_STRIPS][NUM_LEDS];

float c = 0;
void setup() {
  FastLED.addLeds<NUM_STRIPS, WS2812, 0, GRB>(leds[0], NUM_LEDS);
  FastLED.addLeds<NUM_STRIPS, WS2812, 1, GRB>(leds[1], NUM_LEDS);
  FastLED.addLeds<NUM_STRIPS, WS2812, 7, GRB>(leds[2], NUM_LEDS);
  FastLED.addLeds<NUM_STRIPS, WS2812, 8, GRB>(leds[3], NUM_LEDS);
  LEDS.setBrightness(255);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
}

void loop() {
  for (int a = 0; a < NUM_STRIPS; a++) {
    for (int b = 0; b < NUM_LEDS; b++) {
      uint16_t  noiseVal = inoise8(a * SCALE, b * SCALE, c);
      leds[a][b] = CHSV(noiseVal, 255, 255);
    }
  }
  FastLED.show();
  c += .4;
}
