#include <arduino.h>

class VoltageControl {
  public:
    #define powerConrol_PIN A3 //lese aus zum Spannungsmessen

  void initVoltageControl(void);
  float getVoltage(void);
};