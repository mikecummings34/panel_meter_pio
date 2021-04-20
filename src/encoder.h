#ifndef encoder_h
#define encoder_h
#include <Arduino.h>
#include "meter.h"
extern const byte encoderPinA;
extern const byte encoderPinB;
extern volatile int encoderNav;
void enc_increment();
void enc_flag();
void enc_loop();

#endif