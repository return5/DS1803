/*                                           ### description ###                       
    Library file for using a DS1803 dual digital potentiometer with an arduino. 
    please see 'README.txt' for more information

    Copyright (C) <2020>  <Chris Nichols>

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
//A_101 is addres of DS1803 when A2 = 1, A1 = 0, and A0 = 1.
enum ADDRESS_LIST {A_000 = 0x28, A_001 = 0x29, A_010 = 0x2A, A_011 = 0x2B, A_100 = 0x2C, A_101 = 0x2D,A_110 = 0x2E,A_111 = 0x2F};

//---------------------------------------------- typedefs ------------------------------------------------
typedef enum ADDRESS_LIST ADDRESS;

//-------------------------------------------- prototypes -----------------------------------------

//function to set value of wiper. takes in which wiper to write to and the value to write to it.
void setWiper(const ADDRESS address, const int wiper, const int value);

//function which reads the current value for both wipers and prints it to the serial monitor of the arduino
void readWipers(const ADDRESS address);

//function which starts serial communications and starts i2c communication with potentiometer
void initDS1803();
#endif