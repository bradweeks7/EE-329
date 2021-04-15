#include "msp.h"
#include "clk.h"
#include "delay.h"
#include "lcd.h"
#include "keypad.h"

/**
 * main.c
 */

void main(void)
{
    set_DCO(FREQ_3_MHz);
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    //LED colors gpio (P2.0-2.2) for key bits 0-2
    P2->DIR |= 0x07;        //make pins output:  0000 0111
    P2->OUT &= ~0x07;       //turn LED off:      1111 1000
    P1->DIR |= BIT0;        //use red LED for bit key bit 3
    P1->OUT &= ~BIT0;       //turn LED off

    uint8_t key, rgb;       //for rgbs

    LCD_init();
    LCD_command(1);         //clear
    delay_ms(500);
    keypad_init();          //setup GPIO pins for keypad
    while(1){
        key = keypad_getkey();
        if (key != 0xFF){                               //if key is not pressed don't print
            if (key == 10){                             //  * = clear LCD
                LCD_clear();
            }
            else if(key == 12){
                LCD_write('#');                          // if # is pressed, print # on LCD
            }
            else{
                LCD_write(key +'0');
                rgb = key & 0x07;                       // only keep bottom 3 bits
                P2->OUT = (P2->OUT &= ~ 0x07) | rgb;    // zero bottom 3 bits before
                key = (key >> 3);                       // shift bit 4 to bit 0
                P1->OUT = (P1->OUT &= ~BIT0) | key;     // only set bit 0 with key
            }
            delay_ms(200); //delay for E to turn off
        }


    }
}
