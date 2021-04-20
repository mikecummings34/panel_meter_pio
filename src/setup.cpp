#include "setup.h"
//includes setup settings for all program modules

void meter_setup() {
  analogReference(INTERNAL4V3);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void serial_console_setup() {
  Serial.begin(9600);
  Serial.println("start");
}

//lcd_setup function was here. Now in its own file

void push_button_setup() {
  pinMode(buttonPin, INPUT_PULLUP);
}

void encoder_setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), enc_flag, CHANGE);
}