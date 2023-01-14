                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               /*******************************************************************************
  Scrolltext recreated manual by Nicu FLORICA (niq_ro) using base "noiasca" HT16K33 library
 *******************************************************************************/

#include <Wire.h>               // HT16K33 uses I2C, include the Wire Library
#include "NoiascaHt16k33.h"     // include the noiasca HT16K33 library - download from http://werner.rothschopf.net/

Noiasca_ht16k33_hw_14_ext display = Noiasca_ht16k33_hw_14_ext();     // 14 segment, extended class with scroll support

const String   weekDays1[7] = {
  "    Duminica    ",
  "    Luni    ",
  "    Marti    ",
  "    Miercuri    ",
  "    Joi    ",
  "    Vineri    ",
  "    Sambata    "
  };  // lb. romana


const String   weekDays0[7] = {
  "    Saturday    ",
  "    Monday    ",
  "    Tuesday    ",
  "    Wednesday    ",
  "    Thursday   ",
  "    Friday    ",
  "    Sunday    "
  };  // english

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

    String weekDay0 = weekDays0[i];
    char numezi0[20];
    weekDay0.toCharArray(numezi0,weekDay0.length()); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
    Serial.println (numezi0);
    
j = 0;
while (j <= weekDay0.length()-4)
  {
    display.print(numezi0[j]);
    display.print(numezi0[j+1]);
    display.print(numezi0[j+2]);
    display.print(numezi0[j+3]);
    delay(500);
    j++;
  }
display.clear();
    String weekDay1 = weekDays1[i];
    char numezi1[20];
    weekDay1.toCharArray(numezi1,weekDay1.length()); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
    Serial.println (numezi1);

j = 0;
while (j <= weekDay1.length()-4)
  {
    display.print(numezi1[j]);
    display.print(numezi1[j+1]);
    display.print(numezi1[j+2]);
    display.print(numezi1[j+3]);
    delay(500);
    j++;
  }
  
delay(1000);
  i++;
  if (i > 6) i = 0;
}
