#include <arduino.h>
#include <Servo.h>

class MotorControl {
  public:
    #define ServoLenkung_Pin 10 //Servolenkung gebe Grad
    #define ServoFahren_Pin 3 //zum Fahren gebe Wert >90

    void initMotorControl(void);
    void runMotor(int speed, bool print);
};
