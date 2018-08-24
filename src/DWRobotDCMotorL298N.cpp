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

DWRobotDCMotorL298N::DWRobotDCMotorL298N(int pin_dir_bck, int pin_dir_fwd, int pin_speed_pwm)
{
    this->pin_dir_bck = pin_dir_bck;
    this->pin_dir_fwd = pin_dir_fwd;
    this->pin_speed_pwm = pin_speed_pwm;
}

void DWRobotDCMotorL298N::setup()
{
  Serial.println("DWRobotDCMotorL298N::setup() start");

  pinMode(this->pin_dir_bck, OUTPUT);
  pinMode(this->pin_dir_fwd, OUTPUT);
  pinMode(this->pin_speed_pwm, OUTPUT);

  Serial.println("DWRobotDCMotorL298N::setup() finished");
}

void DWRobotDCMotorL298N::speed(int speedValue)
{
  Serial.println("DWRobotDCMotorL298N::speed() start");

  if (speedValue > 0) {
    digitalWrite(this->pin_dir_bck, LOW);
    digitalWrite(this->pin_dir_fwd, HIGH);
    analogWrite(this->pin_speed_pwm, abs(speedValue));
  } else if (speedValue < 0) {
    digitalWrite(this->pin_dir_bck, HIGH);
    digitalWrite(this->pin_dir_fwd, LOW);
    analogWrite(this->pin_speed_pwm, abs(speedValue));
  } else {
    digitalWrite(this->pin_dir_bck, LOW);
    digitalWrite(this->pin_dir_fwd, LOW);
    analogWrite(this->pin_speed_pwm, 0);
  }
  Serial.println("DWRobotDCMotorL298N::speed() finished");
}

void DWRobotDCMotorL298N::stop()
{
  Serial.println("DWRobotDCMotorL298N::stop() start");
  this->speed(0);
  Serial.println("DWRobotDCMotorL298N::stop() finished");
}

void DWRobotDCMotorL298N::forwardSpeed(int speedValue)
{
  Serial.println("DWRobotDCMotorL298N::forwardSpeed() start");
  this->speed(abs(speedValue));
  Serial.println("DWRobotDCMotorL298N::forwardSpeed() finished");
}

void DWRobotDCMotorL298N::backwardSpeed(int speedValue)
{
  Serial.println("DWRobotDCMotorL298N::backwardSpeed() start");
  this->speed(abs(speedValue) * -1);
  Serial.println("DWRobotDCMotorL298N::backwardSpeed() finished");
}
