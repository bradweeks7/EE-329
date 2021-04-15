#include "delay.h"
#include "msp.h"

/*
 * fload_to_int()
 * Inputs: float to be converted to an int
 * Outputs: integer
 *
 * The purpose of this function is to round off the
 * calculation for the 15000 kHz clock delay. As there
 * are 1.5 cycles of this clock speed in 1 microsecond,
 * the clock must be truncated.
 *
 * Note: There could also be a rounding function for this
 * value, however when tested as of 04/11/20, there was less
 * than 1 percent difference between the experimental output
 * and the expected output. This is not enough to warrant
 * another function without specific and stringent constraints.
 *
 */

/*
 * delay_us()
 * Input(s):
 *      unsigned int delay - integer delay in microseconds
 *
 * Output(s):
 *      Void
 *
 * This function takes a clock frequency and a delay integer (in microseconds)
 * and performs a time delay by performing a simple operation at the clock speed
 * enough times to reach that delay. It uses constants found by calculating the amount
 * of internal clock cycles it will take to reach one microsecond depending on the preset
 * clock speed.
 */

void delay_us(unsigned int delay){
    // local scope counter var, reinitialized after every function call
    int i, j = 0;
    int abs_delay = 0;
    int freq = CS->CTL0;
    switch(freq){
            case(FREQ_24_MHz):
                abs_delay = delay/12;
                //for(i=0; i < actual_delay; i++);
                //exit function, no need to check any more
                break;
            case(FREQ_12_MHz):
                abs_delay = delay/14;
                //for(i=0; i < actual_delay; i++);
                break;
            case(FREQ_6_MHz):
                abs_delay = delay/28;
                //for(i=0; i < actual_delay; i++);
                break;
            case(FREQ_3_MHz):
                abs_delay = delay/21;
                //f
            //for(i=0; i < actual_delay; i++);
                break;
            case(FREQ_1500_kHz):
        //truncated delay for for loop
        //int abs_delay = float_to_int(us_1500kHz*delay);
                //abs_delay = delay*us_1500kHz;
                abs_delay = delay/25;
                //for(i=0; i< abs_delay; i++);
                break;

            }
            for(i = 0; i < abs_delay; i++){
                for(j=freq/10000; j>0; j--);
            }
    }


void delay_ms(unsigned int ms_input){
    int actual, j, k;
    int freq = CS->CTL0;
    actual = ms_input/10;
    for(j=0; j<actual; j++) {
        for(k=freq/1000; k>0; k--);
    }
}

