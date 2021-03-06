/*
Copyright (c) 2018 Dave Amphlett. All right reserved.

This file is part of the Davelopware Robotics Library for Arduino (DW Robot Lib).

DW Robot Lib is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.

DW Robot Lib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with DW Robot Lib.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "Arduino.h"
#include "DWRobot2WheelDC.h"

DWRobot2WheelDC::DWRobot2WheelDC(DWRobotDCMotor* pMotorLeft, DWRobotDCMotor* pMotorRight)
{
  this->_pMotorLeft = pMotorLeft;
  this->_pMotorRight = pMotorRight;
}

void DWRobot2WheelDC::setup()
{
  Serial.println("DWRobot2WheelDC::setup() start");

  Serial.print("analogWriteFreq:");
  Serial.println(DWRobot2WheelDC::analog_write_freq);
  analogWriteFreq(DWRobot2WheelDC::analog_write_freq);

  _pMotorLeft->setup();
  _pMotorRight->setup();

  Serial.println("DWRobot2WheelDC::setup() finished");
}

void DWRobot2WheelDC::loop()
{
  // Serial.println("DWRobot2WheelDC::loop() start");

  _moveJustFinished = false;
  this->checkIfWeShouldStopTheMove();

  // Serial.println("DWRobot2WheelDC::loop() finished");
}

DWRobot2WheelDC&  DWRobot2WheelDC::speed(int speedValue)
{
  // Serial.println("DWRobot2WheelDC::speed() start");

  _pMotorLeft->speed(speedValue);
  _pMotorRight->speed(speedValue);

  // Serial.println("DWRobot2WheelDC::speed() finished");
  return *this;
}

DWRobot2WheelDC& DWRobot2WheelDC::forwardSpeed(int speedValue)
{
  // Serial.println("DWRobot2WheelDC::forwardSpeed() start");

  _pMotorLeft->forwardSpeed(speedValue);
  _pMotorRight->forwardSpeed(speedValue);

  // Serial.println("DWRobot2WheelDC::forwardSpeed() finished");
  return *this;
}

DWRobot2WheelDC& DWRobot2WheelDC::backwardSpeed(int speedValue)
{
  // Serial.println("DWRobot2WheelDC::backwardSpeed() start");

  _pMotorLeft->backwardSpeed(speedValue);
  _pMotorRight->backwardSpeed(speedValue);

  // Serial.println("DWRobot2WheelDC::backwardSpeed() finished");
  return *this;
}

DWRobot2WheelDC& DWRobot2WheelDC::leftTurn(int speedValue)
{
  // Serial.println("DWRobot2WheelDC::leftTurn() start");

  _pMotorLeft->backwardSpeed(speedValue);
  _pMotorRight->forwardSpeed(speedValue);

  // Serial.println("DWRobot2WheelDC::leftTurn() finished");
  return *this;
}

DWRobot2WheelDC& DWRobot2WheelDC::rightTurn(int speedValue)
{
  // Serial.println("DWRobot2WheelDC::rightTurn() start");

  _pMotorLeft->forwardSpeed(speedValue);
  _pMotorRight->backwardSpeed(speedValue);

  // Serial.println("DWRobot2WheelDC::rightTurn() finished");
  return *this;
}

DWRobot2WheelDC& DWRobot2WheelDC::forMilliseconds(unsigned long milliseconds)
{
  // Serial.println("DWRobot2WheelDC::forMilliseconds() start");

  Serial.print("DWRobot2WheelDC::forMilliseconds(");Serial.print(milliseconds);Serial.println(")");
  _moveShouldEnd = millis() + milliseconds;
  Serial.print("DWRobot2WheelDC::forMilliseconds() should end:");Serial.print(_moveShouldEnd);Serial.println("");

  // Serial.println("DWRobot2WheelDC::forMilliseconds() finished");
  return *this;
}

DWRobot2WheelDC& DWRobot2WheelDC::stop()
{
  // Serial.println("DWRobot2WheelDC::stop() start");

  _moveShouldEnd = DWRobot2WheelDC::Move_Should_End_Not_Set;
  _pMotorLeft->stop();
  _pMotorRight->stop();

  // Serial.println("DWRobot2WheelDC::stop() finished");
  return *this;
}

bool DWRobot2WheelDC::moveJustFinished()
{
  return _moveJustFinished;
}


void DWRobot2WheelDC::checkIfWeShouldStopTheMove()
{
  // Serial.println("DWRobot2WheelDC::checkIfWeShouldStopTheMove() start");

  unsigned long currentMillis = millis();

  if (_moveShouldEnd != DWRobot2WheelDC::Move_Should_End_Not_Set && currentMillis >= _moveShouldEnd) {
    this->stop();
    _moveJustFinished = true;
    Serial.println("DWRobot2WheelDC::checkIfWeShouldStopTheMove() just finished move");
  }

  // Serial.println("DWRobot2WheelDC::checkIfWeShouldStopTheMove() finished");
}
