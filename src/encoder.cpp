#include "encoder.h"
#include <Arduino.h>
#define readA bitRead(PORTA.IN,0)//faster than digitalRead()
#define readB bitRead(PORTF.IN,5)//faster than digitalRead()
const byte encoderPinA = 2;
const byte encoderPinB = 3;
volatile int encoderNav = 0;
int lastBPinState = HIGH;
unsigned long encDebounceDelay = 4;
int encoderState;
int protectedNav;
int lastProtectedNav = 1; //set to one for initialization
void lcd_setup();
void encoder_setup();
void enc_increment();
void enc_flag();
unsigned long lastTStamp = 0;
int encFlag = 0;

//bool trigger = false;


void enc_loop() {
  if(encFlag == 1) {
    enc_increment();
    noInterrupts();
    protectedNav = encoderNav;
    interrupts();
    encFlag = 0;
  }
  
  if (protectedNav != lastProtectedNav){
    lcd.setCursor(13,0);
    lcd.print(protectedNav);
  }
  lastProtectedNav = protectedNav;
}


void enc_flag() {
  if (encFlag != 1) {  ///may not need this
  volatile long tstamp = millis();
  unsigned long dBounce = (tstamp - lastTStamp);
  if (dBounce > encDebounceDelay) {
    encFlag = 1;
  }
  lastTStamp = tstamp; //once everything is done running, make the current trigger the last trigger.
  }
}


void enc_increment(){  
    if(readB != encoderState) {
      encoderState = readB;
       if (readB == LOW) {
          if(readA != readB) {
            encoderNav--;
          }
          else {
            encoderNav++;
          }
       }
      } 
    
  lastBPinState = readB;
}