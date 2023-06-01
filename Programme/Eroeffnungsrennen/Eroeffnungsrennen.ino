//Programm für die ersten beiden Wettbewerbsrennen

//Motor
#include "MotorControl.h"
extern MotorControl Fahren;

//Lichtsensor
#include "IRSensor.h"
extern IRSensor IR;

//Ultraschall (Servo)
#include "Ultraschallsensor.h"
extern Ultraschallsensor Ultraschall;

//Spannungsmesser
#include "VoltageControl.h"
extern VoltageControl Spannungsmesser;

//LED
#include "LEDControl.h"
extern LEDControl LED;

//MPU6050 (I2C)
#include "MPU6050.h"
extern MPU6050 MPU;

void initAll() {
  //Motor
  Fahren.initMotorControl();

  //IR-Sensor
  IR.initIR();

  //Ultraschallsensor (Servo)
  Ultraschall.initUltraschallsensor();

  //Spannungsmesser
  Spannungsmesser.initVoltageControl();

  //LED
  LED.initLED();
}

void controlVoltage() {
  float voltage = Spannungsmesser.getVoltage();
  Serial.println("Spannung: " + String(voltage) + "V");
  if (voltage >= 8) {
    LED.setColor(LED.getColor(0, 255, 0));
  }
  else {
    LED.setColor(LED.getColor(255, 0, 0));
  }
}

void setup() {
  //Initialisiere Serial
  Serial.begin(9600);
  while(!Serial);
  Serial.println("----Eroeffnungsrennen----");

  //Initialisiere I2C
  MPU.initI2C();

  //Initialisiere Objekte
  initAll();

  //Initialisiere I2C
  Wire.begin(); //Meldung als Host
  MPU.startMPU(true); //starte MPU

  //kontrolliere Spannung
  controlVoltage();
}

void loop() {
  
}
