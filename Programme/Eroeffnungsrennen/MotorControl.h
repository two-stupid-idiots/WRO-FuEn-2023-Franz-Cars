#include <arduino.h>

class MotorControl {
  public:
    #define standBy 3 //setze HIGH für Motorkontrolle
    #define PWMR    5 //setze HIGH für Power bei rechten Motoren
    #define RMR     7 //setze HIGH zum nach vorne fahren
    #define PWML    6 //setze HIGH für Power bei linken Motoren
    #define RML     8 //setze HIGH zum nach vorne fahren

    enum side {
      right,
      left,
      both
    };

    enum motorRotation {
      forward,
      backward
    };

    void initMotorControl(void);
    void runMotor(enum side side, enum motorRotation direction, int speed);
    void go_forward(int speed);
    void go_backward(int speed);
    void stopMotors();
};

