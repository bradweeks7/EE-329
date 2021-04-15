#include "msp.h"
#include "delay.h"
#include <stdio.h>
#include <string.h>

#define RS BIT5     /* P2.5 */
#define RW BIT6     /* P2.6 */
#define EN BIT7     /* P2.7 */

#define CLEAR_DISP 0x01
#define HOME 0x02
#define Four_BIT_MODE 0x03

void delayMs(int n);
void LCD_write(unsigned char data);
void LCD_command(unsigned char command);
void LCD_init(void);
void LCD_clear(void);
void LCD_home(void);
void LCD_string(char *str);
