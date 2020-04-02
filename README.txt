
This is a library for using an arduino to communicate with an Maxim DS1803 dual digital potentiometer. 


-- installation --

    - easiest method when using the arduino IDE
        - download libary as a .zip file
        - open arduino IDE
            - navigate to sketch->include library->add.ZIP library  
            - select DS1803.zip (or the name you gave the .zip file)
            - make sure your program has ' #include "DS1803.h" ' at the top

-- functions ---

    - initDS1803()
        - start communication wiht potentiometers.  call this before you do anything else

    - writeWiper(address,wiper,value)
        - writes value to the given wiper at the given address

    - readWipers(address)
        - reads the current values of the two wipers and prints the information to serial monitor

-- wipers --
    to write to a wiper, you must include the wiper variable. the defined variables are:
        - WIPER_0
        - WIPER_1
        - WIPER_BOTH

-- values --
    value written to wiper must be between 0 and 255.  

-- address --
    - the address of the DS1803 is set by the value of the three address pins: A2,A1,A0.
    - library includes names for each address under the form A_xxx where xxx represents the value of the three address pins.  
        - see table below for values and variables

    -- address truth table --

        address  | A2,A1,A0
        ------------------
        | A_000  |  000  |
        | A_001  |  001  |
        | A_010  |  010  |
        | A_011  |  011  |
        | A_100  |  100  |
        | A_101  |  101  |
        | A_110  |  110  | 
        | A_111  |  111  |    
