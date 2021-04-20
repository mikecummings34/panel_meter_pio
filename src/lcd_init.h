#ifndef lcd_init_h
#define lcd_init_h
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
extern hd44780_I2Cexp lcd;
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
extern byte st[8];
void lcd_setup();

#endif
