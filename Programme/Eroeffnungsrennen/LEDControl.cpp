#include "LEDControl.h"

void LEDControl::initLED(void) {
  CRGB leds[NUM_LEDS];
  FastLED.addLeds<NEOPIXEL, RGB_PIN>(leds, NUM_LEDS); //Initialisiere FastLED
  FastLED.setBrightness(20); //setze LED Helligkeit
}

uint32_t LEDControl::getColor(uint8_t r, uint8_t g, uint8_t b) {
  return (((uint32_t)r << 16) | ((uint32_t)g << 8) | b);
}

void LEDControl::setColor(uint32_t color) {
  FastLED.showColor(color);
}
