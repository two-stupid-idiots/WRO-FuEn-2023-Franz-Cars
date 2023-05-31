//Define Motercontrol Pins
#define FR_speedPin  9  //Pin  9 = Right ENA
#define FR_DirPin1  22  //Pin 22 = Right IN1
#define FR_DirPin2  24  //Pin 24 = Right IN2

#define FL_speedPin 10  //Pin 10 = Right ENB
#define FL_DirPin1  26  //Pin 26 = Right IN3
#define FL_DirPin2  28  //Pin 28 = Right IN4

#define BR_speedPin 11  //Pin 11 = Left  ENA
#define BR_DirPin1   5  //Pin  5 = Left  IN1
#define BR_DirPin2   6  //Pin  6 = Left  IN2

#define BL_speedPin 12  //Pin 12 = Left  ENB
#define BL_DirPin1   7  //Pin  7 = Left  IN3
#define BL_DirPin2   8  //Pin  8 = Left  IN4

//Define Servo Pins
#include <Servo.h>
#define Servo_Pin   13  //Pin 13 = Servo AIM
Servo head;

//Define IR Sensor Pins
#define IR_Sensor_1 A4  //Pin A4 = IR Tracker 1
#define IR_Sensor_2 A3  //Pin A3 = IR Tracker 2
#define IR_Sensor_3 A2  //Pin A2 = IR Tracker 3
#define IR_Sensor_4 A1  //Pin A1 = IR Tracker 4
#define IR_Sensor_5 A0  //Pin A0 = IR Tracker 5

//Define Variables
#define SPEED 100
#define servo_alignment 90

//Initialize Pins
void init_GPIO() {
  pinMode(FR_speedPin, OUTPUT);
  pinMode(FR_DirPin1, OUTPUT);
  pinMode(FR_DirPin2, OUTPUT);

  pinMode(FL_speedPin, OUTPUT);
  pinMode(FL_DirPin1, OUTPUT);
  pinMode(FL_DirPin2, OUTPUT);

  pinMode(BR_speedPin, OUTPUT);
  pinMode(BR_DirPin1, OUTPUT);
  pinMode(BR_DirPin2, OUTPUT);

  pinMode(BL_speedPin, OUTPUT);
  pinMode(BL_DirPin1, OUTPUT);
  pinMode(BL_DirPin2, OUTPUT);

  head.attach(Servo_Pin);

  pinMode(IR_Sensor_1, INPUT);
  pinMode(IR_Sensor_2, INPUT);
  pinMode(IR_Sensor_3, INPUT);
  pinMode(IR_Sensor_4, INPUT);
  pinMode(IR_Sensor_5, INPUT);

  stop();
}

/* Define single moter control
  If driving forward   set DirPin1 to LOW  and DirPin2 to HIGH
  If driving backwards set DirPin1 to HIGH and DirPin2 to LOW
  Don't forget setting speed to speedPin
*/

void FR_fwd(int speed) {
  digitalWrite(FR_DirPin1, LOW);
  digitalWrite(FR_DirPin2, HIGH);
  analogWrite(FR_speedPin, speed);
}
void FR_bck(int speed) {
  digitalWrite(FR_DirPin1, HIGH);
  digitalWrite(FR_DirPin2, LOW);
  analogWrite(FR_speedPin, speed);
}

void FL_fwd(int speed) {
  digitalWrite(FL_DirPin1, LOW);
  digitalWrite(FL_DirPin2, HIGH);
  analogWrite(FL_speedPin, speed);
}
void FL_bck(int speed) {
  digitalWrite(FL_DirPin1, HIGH);
  digitalWrite(FL_DirPin2, LOW);
  analogWrite(FL_speedPin, speed);
}

void BR_fwd(int speed) {
  digitalWrite(BR_DirPin1, LOW);
  digitalWrite(BR_DirPin2, HIGH);
  analogWrite(BR_speedPin, speed);
}
void BR_bck(int speed) {
  digitalWrite(BR_DirPin1, HIGH);
  digitalWrite(BR_DirPin2, LOW);
  analogWrite(BR_speedPin, speed);
}

void BL_fwd(int speed) {
  digitalWrite(BL_DirPin1, LOW);
  digitalWrite(BL_DirPin2, HIGH);
  analogWrite(BL_speedPin, speed);
}
void BL_bck(int speed) {
  digitalWrite(BL_DirPin1, HIGH);
  digitalWrite(BL_DirPin2, LOW);
  analogWrite(BL_speedPin, speed);
}

/*
  motercontrol
*/

void go_advance(int speed) {
  FR_bck(speed);
  FL_bck(speed);
  BR_bck(speed);
  BL_bck(speed);
}

void go_back(int speed) {
  FR_fwd(speed);
  FL_fwd(speed);
  BR_fwd(speed);
  BL_fwd(speed);
}

void shift_right(int speed) {
  FR_bck(speed);
  FL_fwd(speed);
  BR_fwd(speed);
  BL_bck(speed);
}

void shift_left(int speed) {
  FR_fwd(speed);
  FL_bck(speed);
  BR_bck(speed);
  BL_fwd(speed);
}

void clockwise(int speed) {
  FR_bck(speed);
  FL_fwd(speed);
  BR_bck(speed);
  BL_fwd(speed);
}

void counterclockwise(int speed) {
  FR_fwd(speed);
  FL_bck(speed);
  BR_fwd(speed);
  BL_bck(speed);
}

//Define Stop
void stop() {
  analogWrite(FR_speedPin, 0);
  analogWrite(FL_speedPin, 0);
  analogWrite(BR_speedPin, 0);
  analogWrite(BL_speedPin, 0);
}

void test_everything(int speed) {
  head.write(0);
  go_advance(speed);
  delay(2000);
  stop();
  delay(2000);
  head.write(45);
  go_back(speed);
  delay(2000);
  stop();
  delay(2000);
  head.write(90);
  shift_right(speed);
  delay(2000);
  stop();
  head.write(135);
  shift_left(speed);
  delay(2000);
  stop();
  delay(2000);
  head.write(180);
  clockwise(speed);
  delay(2000);
  stop();
  delay(2000);
  counterclockwise(speed);
  delay(2000);
  stop();
  delay(2000);
}

void setup() {
  init_GPIO();
  head.write(servo_alignment);
}

void loop() {
  test_everything(SPEED);
} 
