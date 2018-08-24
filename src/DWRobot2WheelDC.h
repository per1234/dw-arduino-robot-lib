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

  public:
    DWRobot2WheelDC(DWRobotDCMotor motorLeft, DWRobotDCMotor motorRight);
    void setup();
    void loop();
    void forwardSpeed(int speed);
    void backwardSpeed(int speed);
    void speed(int speed);
    void stop();

  private:
    DWRobotDCMotor& _motorLeft;
    DWRobotDCMotor& _motorRight;

};

#endif //DWRobot2WheelDC_h
