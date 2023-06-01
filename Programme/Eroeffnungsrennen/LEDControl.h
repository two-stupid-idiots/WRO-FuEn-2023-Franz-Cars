#include <arduino.h>
#include "FastLED.h"

class LEDControl {
  public:
    #define RGB_PIN  4 //LED PIN
    #define NUM_LEDS 1 //Anzahl der LEDS

    void initLED(void);
    uint32_t getColor(uint8_t r, uint8_t g, uint8_t b);
    void setColor(uint32_t color);
};