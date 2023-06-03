#include "MotorControl.h"

Servo servoLenkung;
Servo servoFahren;

void MotorControl::initMotorControl(void) {
  //Initialisiere Motoren
  servoLenkung.attach(ServoLenkung_Pin);
  servoFahren.attach(ServoFahren_Pin);

  int degree = 90 ; //zwischen 50 (d.h. rechts) und 130 (d.h. links)
  servoLenkung.write(degree);
  Serial.println("Servo Lenkung Position: " + String(degree) + "°");
}

void MotorControl::runMotor(int speed, bool print) { //speed als Zahl über 90
  servoFahren.write(speed);
  if (print)
    Serial.println("Fahren mit " + String(speed));
}
