#include "FastLED.h"

#define PIN_RGB 4
#define NUM_LEDS 1
CRGB leds[NUM_LEDS];

uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
  return (((uint32_t)r << 16) | ((uint32_t)g << 8) | b);
}

void myColor()
{
  int r=255,g=0,b=0;
    for(int i=0;i<255;i++)
    {
      FastLED.showColor(color(r, g, b));
      r-=1;
      g+=1;
      delay(10);
    }
    r=0,g=0,b=255;
    
    for(int i=0;i<255;i++)
    {
      FastLED.showColor(color(r, g, b));
      r+=1;
      b-=1;
      delay(10);
    }
    r=0,g=255,b=0;

    for(int i=0;i<255;i++)
    {
      FastLED.showColor(color(r, g, b));
      g-=1;
      b+=1;
      delay(10);
    }
    r=0,g=0,b=0;
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, PIN_RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
}

void loop() {
  myColor();
}