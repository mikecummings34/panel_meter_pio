#include "lcd_init.h"
hd44780_I2Cexp lcd;

byte st[8]  = {
  B01100,
  B10000,
  B01000,
  B00100,
  B11000,
  B00111,
  B00010,
  B00010,
};
void lcd_setup() {
    int status;
    status = lcd.begin(LCD_COLS,LCD_ROWS);
    if (status) {
        status = -status;
        hd44780::fatalError(status);
    }
    lcd.createChar(1,st);
}