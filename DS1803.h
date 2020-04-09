/*                                           ### description ###                       
    Library file for using a DS1803 dual digital potentiometer with an arduino. 
    please see 'README.txt' for more information

    Copyright (C) <2020>  <Chris Nichols. github/return5>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef DS1803_H    //guard against including the file more than once
#define DS1803_H
//-------------------------------------------- headers --------------------------------------------

#include "Arduino.h"     //give access to the arduino
#include <Wire.h>       //allow library to use the arduino's I2C functions

//-------------------------------------------- define ---------------------------------------------

#define WIPER_0 0xA9        //write to wiper one
#define WIPER_1 0xAA       //write to wiper two
#define WIPER_BOTH 0xAF   //write to both wipers at once

//---------------------------------------------- enums ---------------------------------------------------
//address of DS1803 based on the address lines A2,A1,A0. 
//A_000 == address of DS1803 when A2,A1,A0 are all 0.
//A_101 is address of DS1803 when A2 = 1, A1 = 0, and A0 = 1.
enum ADDRESS_LIST {A_000 = 0x28, A_001, A_010, A_011, A_100, A_101,A_110,A_111};

//---------------------------------------------- typedefs ------------------------------------------------
typedef enum ADDRESS_LIST ADDRESS;

//-------------------------------------------- prototypes -----------------------------------------

//function to set value of wiper. takes in address of device, which wiper to write to and the value to write to it.
void setWiper(const ADDRESS address, const int wiper, const int value);

//function which reads the current value for both wipers at given address and prints them to the serial monitor of the arduino
void readWipers(const ADDRESS address);

//function which starts serial communications and starts i2c communication with potentiometer
void initDS1803();
#endif
