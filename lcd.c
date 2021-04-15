/*
 * lcd.c
 *
 */
#include "lcd.h"

void LCD_init(void) {


    P4->SEL0 &= ~0xFF;  // 8 bit
    P4->SEL1 &= ~0xFF;  // 8 bit data bus
    P2->SEL0 &= ~0xE0; // control lines
    P2->SEL1 &= ~0xE0;

    P2->DIR |= 0xE0;
    P4->DIR |= 0xFF;     /* make P4 pins output for data and controls */

    // power on

    P2->OUT &= ~EN;
    delayMs(10);
    P2->OUT &= ~(RS|RW); //set to 0
    LCD_command(0x30);  // wake up 1
    delayMs(30);
    LCD_command(0x30);  // wake up 2
    delayMs(10);
    LCD_command(0x30);  // wake up 3
    delayMs(10);
    LCD_command(0x38);  // function set: 8-bit/2-line
    LCD_command(0x0F);  // display on, cursor on was 0x0C
    LCD_command(0x10);  // set cursor
    LCD_command(0x06); //Entry mode set
    LCD_clear();
}


void LCD_command(unsigned char data) {
    P2->OUT &= ~RS;
    P2->OUT &= ~RW;
    P2->OUT |= EN;  /* pulse E */
    P4->OUT = data;  // put data on output port
    delayMs(1);
    P2->OUT &= ~EN;
    P2->OUT |= RW;
    P2->OUT |= RS;
    P4->OUT = 0;
}

void LCD_write(unsigned char command) {
    P4->OUT = command;
    P2->OUT &= ~(EN | RS | RW);
    P2->OUT |= RS; //set to 1
    P2->OUT |= EN;
    delay_us(0);
    P2->OUT &= ~EN;
}


void LCD_home(){
    int home = 0x02;
    LCD_write(0x00);
    LCD_command(home);
}

void LCD_clear(){
    int clear = 0x01;
    int home = 0x02;
    //LCD_write(0x00);
    LCD_command(clear);
    LCD_command(home);
}

void LCD_string(char *str){
    int i = 0;
    for (i = 0; i < strlen(str); i++){
        LCD_write(str[i]);
    }
}

/* delay milliseconds when system clock is at 3 MHz */
void delayMs(int n) {
    int i, j;
    for (j = 0; j < n; j++)
        for (i = 750; i > 0; i--);
}

