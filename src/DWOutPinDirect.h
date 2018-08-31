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
#ifndef DWOutPinDirect_h
#define DWOutPinDirect_h

#include "Arduino.h"

class DWOutPinDirect  : public DWOutPin
{
    public:
        void DWOutPinDirect(uint8_t pin);
        void setup();
        void digitalWrite(uint8_t value);

    private:
        uint8_t pin;
};

#endif //DWOutPinDirect_h
