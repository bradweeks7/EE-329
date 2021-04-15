#include "keypad.h"
#include "delay.h"

void keypad_init(void) {
    P5->DIR = 0;                              // direction set
    P5->REN |= (ROW1 | ROW2 | ROW3 | ROW4);   // Resistor enable
    P5->OUT &= ~(ROW1 | ROW2 | ROW3 | ROW4);  // IO set
}

uint8_t keypad_getkey(void){

    uint8_t row, col, key;

    /* check to see any key pressed */
    P5->DIR |= (COL1 | COL2 | COL3);  // make the column pins outputs
    P5->OUT |= (COL1 | COL2 | COL3);  // drive all column pins high
    _delay_cycles(50);                // wait for signals to settle

    row = P5->IN & (ROW1 | ROW2 | ROW3 | ROW4);   // read all row pins

    if (row == 0)           // if all rows are low, no key pressed
        return 0xFF;

    /* If a key is pressed, this for loop will cycle through each column until
     * it finds the corresponding row its voltage change corresponds to */

    for (col = 0; col < 3; col++) {
        P5->OUT &= ~(COL1 | COL2 | COL3);           // bits 4-6 -> 0
        P5->OUT |= (COL1 << col);                   // shift a 1 into the correct column
        _delay_cycles(50);                          // wait for signals to settle
        row = P5->IN & (ROW1 | ROW2 | ROW3 | ROW4); // mask only the row pins

        //key detect, nonzero input => exit
        if (row != 0) {
            break;
        }
    }

    P5->OUT &= ~(COL1 | COL2 | COL3);   // drive all columns low
    P5->DIR &= ~(COL1 | COL2 | COL3);   // disable column outputs

    if (col == 3) {
        return 0xFF;        // no key was detected
    }

    // rows are read in binary, so powers of 2 (1,2,4,8)
    if (row == 4){
        row = 3;
    }
    if (row == 8) {
        row = 4;
    }

    //Note: multiple key presses will cause this segment to behave incorrectly

    // calculate the key value
    if (col == 0) {
        key = row*3 - 2;
    }
    else if (col == 1) {
        key = row*3 - 1;
    }
    else if (col == 2) {
        key = row*3;
    }

    else if (key == 11) {
        key = 0; // fix for 0 key
    }
    return key;
}
