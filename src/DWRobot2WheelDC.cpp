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

Library for ESP8266 ESP-12E robot

 Components:
  2x dc motors driven by L298N driver module
  1x HC-SR04 Ultra Sonic Range Sensor

 ESP-12E Pins assigned as follows:
   GPIO 00 (D3)      L298N IN3          Left Wheel Dir 1
   GPIO 01 (TX)  XXX do not use
   GPIO 02 (D4)      L298N IN1          Right Wheel Dir 1
   GPIO 03 (RX)
   GPIO 04 (D2)      L298N IN4          Left Wheel Dir 2
   GPIO 05 (D1)      L298N ENB          Left Wheel Pulse Width Modulate
   GPIO 06 (CLK) XXX do not use
   GPIO 07 (SD0) XXX do not use
   GPIO 08 (SD1) XXX do not use
   GPIO 09 (SD2) XXX do not use
   GPIO 10 (SD3)
   GPIO 11 (CMD) XXX do not use
   GPIO 12 (D6)      L298N IN2          Right Wheel Dir 2
   GPIO 13 (D7)      L298N ENA          Right Wheel Pulse Width Modulate
   GPIO 14 (D5)
   GPIO 16 (D0)
   GPIO 15 (D8)
*/

#include "Arduino.h"
#include "DWRobot.h"

DWRobot2WheelDC::DWRobot2WheelDC(DWRobotDCMotor& motorLeft, DWRobotDCMotor& motorRight) :
    _motorLeft(motorLeft),
    _motorRight(motorRight)
{
}

void DWRobot2WheelDC::setup()
{
  Serial.println("DWRobot2WheelDC::setup() start");

  analogWriteFreq(DWRobot2WheelDC::analog_write_freq);

  _motorLeft->setup();
  _motorRight->setup();

  Serial.println("DWRobot2WheelDC::setup() finished");
}

void DWRobot2WheelDC::loop()
{
  Serial.println("DWRobot loop");

  digitalWrite(DWRobot::pin_right_wheel_dir_bck, LOW);
  digitalWrite(DWRobot::pin_right_wheel_dir_fwd, HIGH);
  analogWrite(DWRobot::pin_right_wheel_pwm, 900);

  delay(2000);

  digitalWrite(DWRobot::pin_right_wheel_dir_bck, LOW);
  digitalWrite(DWRobot::pin_right_wheel_dir_fwd, LOW);
  analogWrite(DWRobot::pin_right_wheel_pwm, 0);

}

void DWRobot2WheelDC::speed(int speedValue)
{
  Serial.println("DWRobot2WheelDC::speed() start");

  _motorLeft->speed(speedValue);
  _motorRight->speed(speedValue);

  Serial.println("DWRobot2WheelDC::speed() finished");
}

void DWRobot2WheelDC::forwardSpeed(int speedValue)
{
  Serial.println("DWRobot2WheelDC::forwardSpeed() start");

  _motorLeft->forwardSpeed(speedValue);
  _motorRight->forwardSpeed(speedValue);

  Serial.println("DWRobot2WheelDC::forwardSpeed() finished");
}

void DWRobot2WheelDC::backwardSpeed(int speedValue)
{
  Serial.println("DWRobot2WheelDC::backwardSpeed() start");

  _motorLeft->backwardSpeed(speedValue);
  _motorRight->backwardSpeed(speedValue);

  Serial.println("DWRobot2WheelDC::backwardSpeed() finished");
}

void DWRobot2WheelDC::stop()
{
  Serial.println("DWRobot2WheelDC::stop() start");

  _motorLeft->stop();
  _motorRight->stop();

  Serial.println("DWRobot2WheelDC::stop() finished");
}
