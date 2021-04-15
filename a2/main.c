#include "msp.h"
#include "clk.h"
#include "delay.h"

/**
 * main.c
 */

//uint32_t freq;
int i = 0;
void main(void) {
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	// sets led up for output
	P1->SEL0 &= ~BIT0;  /* configure P1.0 as simple i/o */
	P1->SEL1 &= ~BIT0;
	P1->DIR |= BIT0;   /* P1.0 as output pin */

	// clock freq as output
	P4->SEL0 |= BIT3;                               // P4.3 set as GPIO
	P4->SEL1 &= ~BIT3;
	P4->DIR |= BIT3;                                // P4.3 set as output

	// sets pin 3.3 gpio as output to be measured
	P3->SEL0 &= ~BIT3;
	P3->SEL1 &= ~BIT3;
	P3->DIR |= BIT3;

	// set clock speed
	set_DCO(FREQ_6_MHz);

	while(1){
	    //P1->OUT ^= BIT0;  // red toggle
	    //P4->OUT ^= BIT3;
	    //P1->OUT ^= BIT0;
	    P3->OUT ^= BIT3;
	    delay_ms(4000);
	    P3->OUT ^= BIT3;
	    delay_ms(900000);
	}
}



