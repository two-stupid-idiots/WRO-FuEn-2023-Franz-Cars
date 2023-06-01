#include "MotorControl.h"

void MotorControl::initMotorControl(void) {
  //MotorPINs
  pinMode(standBy, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(RMR, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(RML, OUTPUT);
}

void MotorControl::runMotor(enum side side, enum motorRotation direction, int speed) {
  digitalWrite(standBy, HIGH);

  bool dir;
  switch (direction) {
    case forward:
      dir = HIGH;
      break;
    case backward:
      dir = LOW;
      break;
    default:
      stopMotors();
      break;
  }

  switch (side) {
    case right:
      digitalWrite(RMR, dir);
      analogWrite(PWMR, speed);
      break;
    case left:
      digitalWrite(RML, dir);
      analogWrite(PWML, speed);
      break;
    case both:
      digitalWrite(RMR, dir);
      analogWrite(PWMR, speed);
      digitalWrite(RML, dir);
      analogWrite(PWML, speed);
      break;
    default:
      stopMotors();
      break;
  }
}

void MotorControl::go_forward(int speed) {
  runMotor(both, forward, speed);
}

void MotorControl::go_backward(int speed) {
  runMotor(both, backward, speed);
}

void MotorControl::stopMotors() {
  digitalWrite(standBy, LOW);
}
