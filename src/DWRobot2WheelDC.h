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
#ifndef DWRobot2WheelDC_h
#define DWRobot2WheelDC_h

#ifndef DW_ROBOT_ANALOG_WRITE_FREQ
#define DW_ROBOT_ANALOG_WRITE_FREQ 100
#endif // DW_ROBOT_ANALOG_WRITE_FREQ

#include "Arduino.h"
#include "DWRobotDCMotor.h"


class DWRobot2WheelDC
{
  public:
    static const int analog_write_freq = DW_ROBOT_ANALOG_WRITE_FREQ;
    static const int Move_Should_End_Not_Set = -1;

  public:
    DWRobot2WheelDC(DWRobotDCMotor* pMotorLeft, DWRobotDCMotor* pMotorRight);
    void setup();
    void loop();
    DWRobot2WheelDC& forwardSpeed(int speed);
    DWRobot2WheelDC& backwardSpeed(int speed);
    DWRobot2WheelDC& leftTurn(int speedValue);
    DWRobot2WheelDC& rightTurn(int speedValue);
    DWRobot2WheelDC& forMilliseconds(unsigned long milliseconds);
    DWRobot2WheelDC& speed(int speed);
    DWRobot2WheelDC& stop();
    bool moveJustFinished();

  private:
    void checkIfWeShouldStopTheMove();

  private:
    DWRobotDCMotor* _pMotorLeft;
    DWRobotDCMotor* _pMotorRight;
    unsigned long   _moveShouldEnd = DWRobot2WheelDC::Move_Should_End_Not_Set;
    bool            _moveJustFinished = false;
};

#endif //DWRobot2WheelDC_h
