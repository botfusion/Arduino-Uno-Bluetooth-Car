/* 
    Arduino UNO Bluetooth Car
    Version 1.0.5
    Date: 23.03.2025
*/

#include "UnoConfig.h"

int delay_time = 5;
int speed = 0;
int increment = 20; //Acceleration
char currentCommand = ' ';

unsigned long previousMillis = 0;
const long interval = 1; // Interval between speed changes

void setMotorSpeed(int direction, bool rightTurn = false, bool leftTurn = false) {
  if (rightTurn) {
    FML.run(direction); 
    BML.run(direction);
    FML.setSpeed(speed);
    BML.setSpeed(speed);

    FMR.run(BACKWARD);
    BMR.run(BACKWARD);
    FMR.setSpeed(speed);
    BMR.setSpeed(speed);

  } else if (leftTurn) {
    FML.run(BACKWARD);
    BML.run(BACKWARD);
    FML.setSpeed(speed);
    BML.setSpeed(speed);

    FMR.run(direction);
    BMR.run(direction);
    FMR.setSpeed(speed);
    BMR.setSpeed(speed);
  } else {
    //Serial.println(direction); //1 is forward, 2 is reverses
    FMR.run(direction);
    FML.run(direction);
    BMR.run(direction);
    BML.run(direction);
    FMR.setSpeed(speed);
    FML.setSpeed(speed);
    BMR.setSpeed(speed);
    BML.setSpeed(speed);
  }
}


void setup() {
  // Begin serial communication
  Serial.begin(9600);
  
  // Begin serial communication with Arduino and HC-05
  mySerial.begin(9600);

  delay(1000);
  Serial.println("Started");
}

void loop() {
  if (mySerial.available()) {
    currentCommand = mySerial.read();
    Serial.print("Data = "); 
    Serial.println(currentCommand); // Print received data
  }

  unsigned long currentMillis = millis();

  //Will execute until next command is not received  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    controlMotors();
  }
}

void controlMotors() {
  switch (currentCommand) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'R':
      turnRight();
      break;
    case 'L':
      turnLeft();
      break;
    default:
      stopMotors();
      break;
  }
}

void moveForward() {
  if (speed < 250 && increment > 0) {
    speed += increment;
  } else if (speed > 0 && increment < 0) {
    speed += increment;
  } else {
    increment = 0; // Maintain speed
  }

  setMotorSpeed(FORWARD);
}

void moveBackward() {
  if (speed < 250 && increment > 0) {
    speed += increment;
  } else if (speed > 0 && increment < 0) {
    speed += increment;
  } else {
    increment = 0; // Maintain speed
  }

  setMotorSpeed(BACKWARD);
}

void turnRight() {
  if (speed < 250 && increment > 0) {
    speed += increment;
  } else if (speed > 0 && increment < 0) {
    speed += increment;
  } else {
    increment = 0; // Maintain speed
  }

  setMotorSpeed(FORWARD, true, false);
}

void turnLeft() {
  if (speed < 250 && increment > 0) {
    speed += increment;
  } else if (speed > 0 && increment < 0) {
    speed += increment;
  } else {
    increment = 0; // Maintain speed
  }

  setMotorSpeed(FORWARD, false, true);
}

void stopMotors() {
  speed = 0;
  increment = 1;
  FMR.run(RELEASE);
  FML.run(RELEASE);
  BMR.run(RELEASE);
  BML.run(RELEASE);
}

