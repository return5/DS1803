/*                                           ### description ###      
    example code for using the DS1803.h library with an arduino to control multiple DS1803 dual digital potentiometer. 
    calling function 'initDS1803' starts communication with the DS1803.
    calling the function 'setWiper' allows user to write a value to the given wiper at a given address;
        Wipers are: WIPER_0, WIPER_1, WIPER_BOTH.  
        accepted values are in the range [0,255]. 
        accepted addresses are A_000 through A_111.
        addresses are based on address lines of the device you want to read/write to. see README.txt and datasheet for more information
    calling function 'readWiper' allows user to read the current value of the wipers at the given address.
    DEVICES is an array of addresses for each of the DS1803 chips.
        DEVICES[0] is chip 1
        DEVICES[1] is chip 2
        DEVICES[2] is chip 3
    each of the chips has its own address based on the three address lines
        DEVICES[0] has address A_000 since A2,A1,A0 = 000
        DEVICES[1] has address A_001 since A2,A1,A0 = 001
        DEVICES[2] has address A_011 since A2,A1,A0 = 011
    prints messages to serial monitor.
*/              

#include "DS1803.h"   //library file needed to read/write values to the DS1803 dual digital potentiometer

ADDRESS DEVICES[3];  //global array of three device addresses. 

void setup() {
    initDS1803();                       //start communicating with the DS1803 chip 
    DEVICES[0] = A_000;                 //set address of chip 1 to A_000 based on its address lines
    DEVICES[1] = A_001;                 //set address of chip 2 to A_001 based on its address lines
    DEVICES[2] = A_011;                 //set address of chip 3 to A_011 based on its address lines

    setWiper(DEVICES[0],WIPER_0,0);          //write value 0 to wiper 0 on chip 1.
    setWiper(DEVICES[1],WIPER_1,255);        //write value 255 to wiper 1 on chip 2
    readWipers(DEVICES[1]);                 //prints current value of the wipers of chip 2 in the arduino's serial monitor 
    setWiper(DEVICES[2],WIPER_BOTH,100);   //write value 100 to both wipers on chip 3
    setWiper(DEVICES[1],WIPER_BOTH,300);  //trying to write an incorrect value will give an error message in serial monitor.

    for(int i = 0; i < 3; i++) {
        readWipers(DEVICES[i]);     //loop through and print the value for both wipers on each of the three chips. prints to arduino's serial monitor
    }
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //not needed in this example
}
