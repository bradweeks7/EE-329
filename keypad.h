/*
 * keypad.h
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "msp.h"
//for console printouts
#include <stdint.h>
#include <stdio.h>

// for the keypad
#define COL1  BIT4
#define COL2  BIT5
#define COL3  BIT6
#define ROW1  BIT0
#define ROW2  BIT1
#define ROW3  BIT2
#define ROW4  BIT3

void keypad_init(void);
uint8_t keypad_getkey(void);

#endif /* KEYPAD_H_ */
