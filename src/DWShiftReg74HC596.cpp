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

#include "DWShiftReg74HC595.h"

void DWShiftReg74HC595::DWShiftReg74HC595(uint8_t pin_serial_input, uint8_t pin_serial_clock, uint8_t pin_latch)
{
    this->pin_serial_input = pin_serial_input;
    this->pin_serial_clock = pin_serial_clock;
    this->pin_latch = pin_latch;
    this->outputCache = 0;
}

void DWShiftReg74HC595::setup()
{
    pinMode(this->pin_serial_input, OUTPUT);
    pinMode(this->pin_serial_clock, OUTPUT);
    pinMode(this->pin_latch, OUTPUT);

    digitalWrite(this->pin_serial_input, LOW);
    digitalWrite(this->pin_serial_clock, LOW);
    digitalWrite(this->pin_latch, LOW);
}

void DWShiftReg74HC595::setPinImmediate(uint8_t pin, uint8_t value)
{
    bitWrite(this->outputCache, pin, value);
    this->completeBatch();
}

void DWShiftReg74HC595::startBatch()
{

}

void DWShiftReg74HC595::setPinBatch(uint8_t pin, uint8_t value)
{
    bitWrite(this->outputCache, pin, value);
}

void DWShiftReg74HC595::completeBatch()
{
    digitalWrite(this->pin_latch, LOW);
    digitalWrite(this->pin_serial_clock, LOW);
//    delay(10);

    shiftOut(this->pin_serial_input, this->pin_serial_clock, MSBFIRST, this->outputCache);

//    delay(10);
    digitalWrite(this->pin_latch, HIGH);

//    delay(10);
    digitalWrite(this->pin_serial_clock, LOW);
    digitalWrite(this->pin_latch, LOW);
}
