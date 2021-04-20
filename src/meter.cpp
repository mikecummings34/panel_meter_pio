
#include "meter.h"

float voltageIn = 0.0;
float vin = 0.0;
float temp = 0.0;
float r1 = 100000.0;
float r2 = 25869.096;
int analogPin = A0;
int analogV = 0;
//for smoothing
const int numReadings = 100;
float total = 0.0;                  // the running total
float average = 0.0;                // the average
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading

float voltage_meter() {
  // do some stuff here - the joy of interrupts is that they take care of themselves
  //analogV = analogRead(analogPin);
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(analogPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;
  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;
  //vin did equal analogV var but now used the average var
  vin = (average * 4.316) / 1024.0;
  voltageIn = vin / (r2 / (r2 + r1)); ///Print this variable only if there are voltage dividers. r1 and r2 need to be changed from 0
  if (voltageIn < 0.1) {
    voltageIn = 0.0;
  }
  lcd.setCursor(2, 0);
  lcd.print(voltageIn, 4);
  lcd.setCursor(12,0);
  lcd.setCursor(2, 1);
  lcd.print(voltageIn, 2);
}





void meter_display() {
  voltageIn = voltage_meter();
  //add current funcion call here
  lcd.setCursor(0,0);
  lcd.print("V=");
  lcd.setCursor(9,0);
  lcd.print("V");
  lcd.write(1);
  lcd.print("=");
  lcd.setCursor(0,1);
  lcd.print("I=");
  lcd.setCursor(7,1);
  lcd.print("I");
  lcd.write(1);
  lcd.print("=");
}


