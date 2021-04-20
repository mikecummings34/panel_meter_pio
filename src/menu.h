#ifndef menu_h
#define menu_h
#include <Arduino.h>
#include "button.h"
#include "lcd_init.h"
#include "meter.h"
int long_menu(int reading, int lastButtonState, int btnCheck);
void button_menu_action(int reading, int lastButtonState,  int btnCheck);

#endif