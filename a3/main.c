#include "msp.h"
#include "clk.h"
#include "lcd.h"
#include "delay.h"


int main(void) {

    LCD_init();
    delayMs(1000);
    for(;;) {
        LCD_command(0x80); //line 1
        LCD_string("      Alex...    ");
        LCD_command(0xC0); // 2nd line
        LCD_string("Trav Scott Fortnite?");
        delayMs(5000);
        LCD_clear();
    }
}


