#include "menu.h"

int long_menu (int reading, int lastButtonState, int btnCheck) {
  lcd.clear();
  lcd.print("readg=");
  lcd.setCursor(6, 0);
  lcd.print(reading);
  lcd.setCursor(8, 0);
  lcd.print("lstate=");
  lcd.setCursor(15, 0);
  lcd.print(lastButtonState);
  lcd.setCursor(0, 1);
  lcd.print("btnCheck");
  lcd.setCursor(8, 1);
  lcd.print(btnCheck);
  lcd.setCursor(9, 1);
  lcd.print("tgl");
  lcd.print(tgl);
}

void nav_control (int reading, int lastButtonState, int btnCheck) {
  if (lastMenu != tgl) {
    lcd.clear();
    switch (tgl) {
      case 0:
        meter_display();
        break;
      case 1:
        long_menu(reading, lastButtonState, btnCheck);
        break;
      case 2:
        lcd.cursor();
        lcd.print("[ Calibrate]");
        break;
      case 3:
        lcd.cursor();
        lcd.print("[ Settings]");
        break;
    }
    lastMenu = tgl;
  }
  else if (lastMenu == 0 and tgl == 0) {
    meter_display();
  }

}





/*function to track menu navigator toggle and change menus. Must pass current pin reading and the result from button_check function*/

void button_menu_action(int reading, int lastButtonState, int btnCheck) {
  if (btnCheck == 1) {
    if (tgl != 3) {
      tgl++;
    }
    else {
      tgl = 0;
    }
  }
  else {
    nav_control(reading, lastButtonState, btnCheck);
  }

  if (tgl == 0) {
    meter_display(); //if this works, split the meter display into two functions one for printing names and the other for readings.
  }
}