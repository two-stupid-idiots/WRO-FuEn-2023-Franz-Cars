#include <arduino.h>

class IRSensor {
  public:
    #define IR_Links  A2 //
    #define IR_Mitte  A1 //je kleiner, desto mehr Licht wird reflektiert
    #define IR_Rechts A0 //

    void initIR(void);
    float getLeftInfrared(bool print);
    float getMiddleInfrared(bool print);
    float getRightInfrared(bool print);
};