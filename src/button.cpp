#include "button.h"

int const buttonPin = 12;
int buttonState;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
float ctr = 0;
int tgl = 0;
int lastMenu = 0;

int button_check() {
  int reading = button_reading();
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        return 1;
      }
    }
  }
  lastButtonState = reading;
  return 0;
}

/*
 * this is set seperatly from the check function so that it can be passed as an argument to the menu function in the main loop.  The better option would be to make this into a class.
 */
int button_reading() {
  int readpin = digitalRead(buttonPin);
  return readpin;
}