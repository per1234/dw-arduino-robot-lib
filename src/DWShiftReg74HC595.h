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
#ifndef DWShiftReg74HC595_h
#define DWShiftReg74HC595_h

#include "Arduino.h"

class DWShiftReg74HC595
{
    public:
        void DWShiftReg74HC595(uint8_t pin_serial_input, uint8_t pin_serial_clock, uint8_t pin_latch);
        void setup();
        void setPinImmediate(uint8_t pin, uint8_t value);
        void startBatch();
        void setPinBatch(uint8_t pin, uint8_t value);
        void completeBatch();

    private:
        uint8_t pin_serial_input;
        uint8_t pin_serial_clock;
        uint8_t pin_latch;
        byte outputCache;
};

#endif //DWShiftReg74HC595_h
