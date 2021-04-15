#include "clk.h"
#include "msp.h"

/*
 * set_DCO
 * Input: uint32_t frequency to be tuned to
 * Output: Void
 *
 * Sets the digitally controlled oscillator to any of the present frequencies
 * listed in clk.h
 */
void set_DCO(uint32_t freq){
    switch(freq)
    {
    case FREQ_1500_kHz:
        unlock_clk();
        CS->CTL0 = 0; //clear register CTL0
        CS->CTL0 = FREQ_1500_kHz; //sets clock frequency
        CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3; //decides which internal clock to use
        lock_clk(); // prevents overwriting of the set clock frequency
        break;
    case FREQ_3_MHz:
        unlock_clk();
        CS->CTL0 = 0;
        CS->CTL0 = FREQ_3_MHz;
        CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
        lock_clk();
        break;
    case FREQ_6_MHz:
        unlock_clk();
        CS->CTL0 = 0;
        CS->CTL0 = FREQ_6_MHz;
        CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
        lock_clk();
        break;
    case FREQ_12_MHz:
        unlock_clk();
        CS->CTL0 = 0;
        CS->CTL0 = FREQ_12_MHz;
        CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
        lock_clk();
        break;
    case FREQ_24_MHz:
        unlock_clk();
        CS->CTL0 = 0;
        CS->CTL0 = FREQ_24_MHz;
        CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
        lock_clk();
        break;
    /*case FREQ_48_MHz:
        unlock();
        CS->CTL0 = 0; // clear register CTL0
        CS->CTL0 = FREQ_48_MHz; // set DCO to 48MHz
        // Select MCLK = DCO, no divider
        CS->CTL1 = CS->CTL1 & ~(CS_CTL1_SELM_MASK | CS_CTL1_DIVM_MASK) | CS_CTL1_SELM_3;
        lock_clk();
    */
    }

}

/*
 * unlock_clk()
 * Inputs: Void
 * Outputs: Void
 *
 * unlock_clk() unlocks the register that keeps the DCO from taking
 * in random inputs as a valid set frequency
 */
void unlock_clk(){
    CS->KEY = CS_KEY_VAL;  // unlock CS registers
}

/*
 * lock_clk()
 * Inputs: Void
 * Outputs: Void
 *
 * lock_clk() re-locks the register that keeps the DCO from taking
 * in random inputs as a valid set frequency
 */
void lock_clk(){
    CS->KEY = 0;
}
