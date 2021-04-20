#ifndef setup_h
#define setup_h
#include <Arduino.h>
#include "lcd_init.h"
#include "menu.h"
#include "meter.h"
#include "button.h"
#include "encoder.h"
void meter_setup();
void serial_console_setup();
void push_button_setup();
void encoder_setup();
#endif