#include <Arduino.h>
#include "lcd_init.h"
#include "setup.h"
int ledPin = 9;
int protectedCount;






void setup() {
  // put your setup code here, to run once:
  lcd_setup();
  meter_setup();
  serial_console_setup();
  push_button_setup();
  encoder_setup();
  //testing variables



}

void loop() {
  enc_loop(); //this includes everyhing including to clear and print the value
  meter_display();
  /*
  int reading = button_reading();
  int btnCheck = button_check();


  if (encoderNav > 7) {
    digitalWrite(ledPin, HIGH);
  }
  else digitalWrite(ledPin,LOW);
  button_menu_action(reading, lastButtonState, btnCheck);
  */

}
///loop should read the voltage and print and then be interupted.