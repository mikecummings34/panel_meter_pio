#ifndef button_h
#define button_h
#include <Arduino.h>
extern int const buttonPin;
extern int lastMenu;
extern int tgl;
extern int lastButtonState;
extern int button_check();
extern int button_reading();
#endif