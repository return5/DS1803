/*                                           ### description ###      
    example code for using the DS1803.h library with an arduino to control a DS1803 dual digital potentiometer. 
    calling function 'initDS1803' starts communication with the DS1803.
    calling the function 'setWiper' allows user to write a value to the given wiper at a given address;
        Wipers are: WIPER_0, WIPER_1, WIPER_BOTH.  
        accepted values are in the range [0,255]. 
        accepted addresses are A_000 through A_111.
        addresses are based on address lines of the device you want to read/write to. see README.txt and datasheet for more information
    calling function 'readWiper' allows user to read the current value of the wipers.
    prints messages to serial monitor.
*/              

#include "DS1803.h"   //library file needed to read/write values to the DS1803 dual digital potentiometer

void setup() {
    initDS1803();                       //start communicating with the DS1803 chip 
    setWiper(A_000,WIPER_0,0);          //write value 0 to wiper 1 at adress 000
    setWiper(A_000,WIPER_1,255);       //write value 255 to wiper 2 at adress 000
    readWipers(A_000);                //prints current value of the wipers in serial monitor at adress 000
    setWiper(A_000,WIPER_BOTH,100);   //write value 100 to both wipers  at adress 000
    setWiper(A_000,WIPER_BOTH,300);  //trying to write an incorrect value will give an error message in serial monitor
    readWipers(A_000);              //prints current value of the wipers in serial monitor at adress 000
}

void loop() {
  // put your main code here, to run repeatedly:
}
