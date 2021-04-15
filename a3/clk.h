//includes board header
#include "msp.h"

//frequency defines for readablility in clk.c functions
#define FREQ_1500_kHz ((uint32_t)0x00000000)
#define FREQ_3_MHz    ((uint32_t)0x00010000)
#define FREQ_6_MHz    ((uint32_t)0x00020000)
#define FREQ_12_MHz   ((uint32_t)0x00030000)
#define FREQ_24_MHz   ((uint32_t)0x00040000)
#define FREQ_48_MHz   ((uint32_t)0x00050000)


//these functions make the code more readable
void unlock_clk();
void lock_clk();

//sets Digitally controlled oscillator
void set_DCO(uint32_t freq);

