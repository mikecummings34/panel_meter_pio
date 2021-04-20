#ifndef meter_h
#define meter_h
#include <Arduino.h>
#include "lcd_init.h"
/*
float voltageIn;
float vin;
float temp;
float r1;
float r2;
int analogPin;
int analogV;
//for smoothing
const int numReadings = 100;
float total;                 // the running total
float average;                // the average
int readings[numReadings];      // the readings from the analog input
int readIndex;              // the index of the current reading
int encoder_nav;
*/

extern const int numReadings;
extern int readings[100];
float voltage_meter();
void meter_display();

#endif