#include <arduino.h>
#include <Wire.h>

class MPU6050 {
  public:
    #define MPU_address 0x68
    int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

    void initI2C(void);
    void startMPU(bool print);
    void printI2CError(int error);
};