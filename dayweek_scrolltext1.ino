/*******************************************************************************
  Scrolltext recreated manual by Nicu FLORICA (niq_ro) using base "noiasca" HT16K33 library
  v.1 - added a maxitrix for 2 lanhuages  instead 2 strings
 *******************************************************************************/

#include <Wire.h>               // HT16K33 uses I2C, include the Wire Library
#include "NoiascaHt16k33.h"     // include the noiasca HT16K33 library - download from http://werner.rothschopf.net/

Noiasca_ht16k33_hw_14_ext display = Noiasca_ht16k33_hw_14_ext();     // 14 segment, extended class with scroll support

const String   weekDays[7][2] = {
  "    Saturday    ", "    Duminica    ",
  "    Monday    ", "    Luni    ",
  "    Tuesday    ", "    Marti    ",
  "    Wednesday    ", "    Miercuri    ",
  "    Thursday   ", "    Joi    ",
  "    Friday    ", "    Vineri    ",
  "    Sunday    ", "    Sambata    "
  };  // english, lb. romana

byte a = 0;
int i = 0;
int j =4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(F("\nScroll a text"));
  Wire.begin();                                  // start the I2C interface
  //Wire.setClock(400000);                       // optional: activate I2C fast mode. If it is to fast for other I2C devices deactivate this row.
  display.begin(0x70, 1);                        // I2C adress of first display, in total we use 3 displays
  if (display.isConnected() == false)            // check if all HT16K33 are connected
    Serial.println(F("E: display error"));
  display.setDigits(4);                          // if your modules are not using all 8 digits, reduce the used digits
}

void loop() {
display.clear();
display.print(i);
delay(1000);
display.clear();

    String weekDay = weekDays[i][a%2];
    char numezi[20];
    weekDay.toCharArray(numezi,weekDay.length()); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
    Serial.println (numezi);
    
j = 0;
while (j <= weekDay.length()-4)
  {
    display.print(numezi[j]);
    display.print(numezi[j+1]);
    display.print(numezi[j+2]);
    display.print(numezi[j+3]);
    delay(500);
    j++;
  }
display.clear();


delay(1000);
  i++;
  if (i > 6)
  {
    a++;
    i = 0;
  }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
