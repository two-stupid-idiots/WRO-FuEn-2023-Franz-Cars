#include <arduino.h>
#include <Servo.h>

class Ultraschallsensor {
  public:
    #define TRIG_PIN 13 //sende Schallwelle
    #define ECHO_PIN 12 //empfange Schallwelle
    #define Servo_PIN 10 //schreibe Position in Grad

    void initUltraschallsensor(void);
    int getUltrasonic(int degree, bool print);
    void setServoPosition(int degree, bool print);
};