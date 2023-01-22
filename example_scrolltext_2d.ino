/*******************************************************************************
  Pseudoclock + weather station with Scrolltext recreated manual by Nicu FLORICA (niq_ro) using base "noiasca" HT16K33 library
  ver.2d - added full test value (preset values)
 *******************************************************************************/

#include <Wire.h>               // HT16K33 uses I2C, include the Wire Library
#include "NoiascaHt16k33.h"     // include the noiasca HT16K33 library - download from http://werner.rothschopf.net/

Noiasca_ht16k33_hw_14_ext display = Noiasca_ht16k33_hw_14_ext();     // 14 segment, extended class with scroll support

int i = 0;
int j = 4;

int pauzamica = 150;
int pauzamare = 3000;
int ora, minut;

int humidity = 0;
int temperature = 0;
int temperature2 = 0;

int testt[5] = {-43,-2,0,5,16};
int testh[5] = {0,5,10,15,99};
int testo[5]= {1,6,9,12,20};
int testm[5]= {1,15,59,5,45};
int n = 0;

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
/*
ora = random(24);
minut = random(60);
temperature = random(100) - 50;
temperature = -43;
humidity = random(100);
*/
ora = testo[n];
minut = testm[n];
temperature = testt[n];
humidity = testh[n];

  Serial.print(ora);
  Serial.println(":");
  Serial.println(minut);
  
    String intrare = "    ";
    if (ora < 10) 
        intrare = intrare + " ";
        else
        intrare = intrare + ora/10;
    intrare = intrare + ora%10;
    intrare = intrare + minut/10;
    intrare = intrare + minut%10;    
    Serial.println (intrare);
    char intrare_char[9];
    intrare.toCharArray(intrare_char,intrare.length()+1); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
        
Serial.println (intrare_char);  
j = 0;
while (j <= 4)
  {
    display.print(intrare_char[j]);
    display.print(intrare_char[j+1]);
    display.print(intrare_char[j+2]);
    display.print(intrare_char[j+3]);
    delay(pauzamica);
    j++;
  }

display.clear();

j = 0;
while (j < 10)
{
   //   if (ora < 10) display.print(F("0"));
      if (ora < 10) display.print(F(" "));
      display.print(ora);
      if (millis()/1000%2 == 0)
      display.print(F("."));
      if (minut < 10) display.print(F("0"));
      display.print(minut);  
      delay(500); 
      j++;
}
//delay(4000);
display.clear();
  
    String iesire = "";
    if (ora < 10) 
        iesire = iesire + " ";
        else
        iesire = iesire + ora/10;
    iesire = iesire + ora%10;
    iesire = iesire + minut/10;
    iesire = iesire + minut%10;
    iesire = iesire + "    "; 
    Serial.print("iesire = "); 
    Serial.println (iesire);
    char iesire_char[9];
    iesire.toCharArray(iesire_char,iesire.length()+1); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
    Serial.println (iesire_char);

j = 0;
while (j <= 4)
  {
    display.print(iesire_char[j]);
    display.print(iesire_char[j+1]);
    display.print(iesire_char[j+2]);
    display.print(iesire_char[j+3]);
    delay(pauzamica);
    j++;
  }
display.clear();


// temperature
//in
    String intrare2 = "    ";
    if (temperature >= 0)
      {
        temperature2 = temperature;
      if (temperature2/10 == 0)
      intrare2 = intrare2 + " ";
      else
      intrare2 = intrare2 + temperature2/10;
      intrare2 = intrare2 + temperature2%10;
      intrare2 = intrare2 + "%";
      intrare2 = intrare2 + "C"; 
      }  
    else  // if temperture is negative
     {
      temperature2 = -temperature;
      intrare2 = intrare2 + "-";
       if (temperature2 < 10)
       {
       intrare2 = intrare2 + temperature2%10;
       intrare2 = intrare2 + "%";
       intrare2 = intrare2 + "C";
       }
       else
       {
       intrare2 = intrare2 + temperature2/10;
       intrare2 = intrare2 + temperature2%10;
       intrare2 = intrare2 + "C"; 
       } 
     }
    Serial.println (intrare2);
    char intrare_char2[9];
    intrare2.toCharArray(intrare_char2,intrare2.length()+1); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
        
Serial.println (intrare_char2);  
j = 0;
while (j <= 4)
  {
    display.print(intrare_char2[j]);
    display.print(intrare_char2[j+1]);
    display.print(intrare_char2[j+2]);
    display.print(intrare_char2[j+3]);
    delay(pauzamica);
    j++;
  }

// static
if (temperature >= 0)
 {
  temperature2 = temperature;
  if (temperature2 < 10) display.print(F(" "));
  display.print(temperature2);
  display.print("%C"); 
 }
else
 {
  temperature2 = -temperature;
  display.print("-");
  display.print(temperature2);
  if (temperature2 < 10)
  display.print("%C"); 
  else
  display.print("C");  
 }
  delay(pauzamare);
  display.clear();

// gone
    String iesire2 = "";
   if (temperature >= 0)
      {
      temperature2 = temperature;
      if (temperature2/10 == 0)
      iesire2 = iesire2 + " ";
      else
      iesire2 = iesire2 + temperature2/10;
      iesire2 = iesire2 + temperature2%10;
      iesire2 = iesire2 + "%";
      iesire2 = iesire2 + "C"; 
      }  
    else  // if temperature is negative
     {
      temperature2 = -temperature;
      iesire2 = iesire2 + "-";
       if (temperature2 < 10)
       {
       iesire2 = iesire2 + temperature2%10;
       iesire2 = iesire2 + "%";
       iesire2 = iesire2 + "C";
       }
       else
       {
       iesire2 = iesire2 + temperature2/10;
       iesire2 = iesire2 + temperature2%10;
       iesire2 = iesire2 + "C"; 
       } 
     }
     iesire2 = iesire2 + "    "; 
       
    Serial.print("iesire2 = "); 
    Serial.println (iesire2);
    char iesire_char2[9];
    iesire2.toCharArray(iesire_char2,iesire2.length()+1); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
    Serial.println (iesire_char2);

j = 0;
while (j <= 4)
  {
    display.print(iesire_char2[j]);
    display.print(iesire_char2[j+1]);
    display.print(iesire_char2[j+2]);
    display.print(iesire_char2[j+3]);
    delay(pauzamica);
    j++;
  }
display.clear();

// humidity simulate
 if (humidity >= 100) humidity = 99;

// in
    String intrare1 = "    ";
    if (humidity/10 == 0) 
    intrare1 = intrare1 + " ";
    else
    intrare1 = intrare1 + humidity/10;
    intrare1 = intrare1 + humidity%10;
    intrare1 = intrare1 + "%";
    intrare1 = intrare1 + "o";    
    Serial.println (intrare1);
    char intrare_char1[9];
    intrare1.toCharArray(intrare_char1,intrare1.length()+1); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
        
Serial.println (intrare_char1);  
j = 0;
while (j <= 4)
  {
    display.print(intrare_char1[j]);
    display.print(intrare_char1[j+1]);
    display.print(intrare_char1[j+2]);
    display.print(intrare_char1[j+3]);
    delay(pauzamica);
    j++;
  }

// static
  if (humidity < 10) display.print(F(" "));
  display.print(humidity);
  display.print("%o"); 
  delay(pauzamare);
  display.clear();

// gone
    String iesire1 = "";
    if (humidity/10 == 0) 
    iesire1 = iesire1 + " ";
    else
    iesire1 = iesire1 + humidity/10;
    iesire1 = iesire1 + humidity%10;
    iesire1 = iesire1 + "%";;
    iesire1 = iesire1 + "o";;
    iesire1 = iesire1 + "    "; 
    Serial.print("iesire1 = "); 
    Serial.println (iesire1);
    char iesire_char1[9];
    iesire1.toCharArray(iesire_char1,iesire1.length()+1); // https://www.tutorialspoint.com/convert-string-to-character-array-in-arduino
    Serial.println (iesire_char1);

j = 0;
while (j <= 4)
  {
    display.print(iesire_char1[j]);
    display.print(iesire_char1[j+1]);
    display.print(iesire_char1[j+2]);
    display.print(iesire_char1[j+3]);
    delay(pauzamica);
    j++;
  }
display.clear(); 

n++;
if (n > 4) n=0;
}  // end main loop�����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
