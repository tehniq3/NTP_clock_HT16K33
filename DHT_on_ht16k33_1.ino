// info on HT16k33 4 digit 14-segment display by Nicu FLORICA (niq_ro)

#include <Wire.h>                                          // needed for the i2c
#include "NoiascaHt16k33.h"                                // include the noiasca HT16K33 library - download from http://werner.rothschopf.net/
#include "DHTesp.h" // Click here to get the library: https://www.arduinolibraries.info/libraries/dht-sensor-library-for-es-px

Noiasca_ht16k33_hw_14 display = Noiasca_ht16k33_hw_14();   // 14 segment - Present time

DHTesp dht;
#define DHTPIN 13 // GPIO13 = D7    // what pin we're connected the DHT output
int temperature, humidity;

int pauza = 3000;
int pauzamica = 300;

void setup() {
  Serial.begin(9600);
  Wire.begin();                                  // start the I2C interface
  Wire.setClock(400000);                         // optional: activate I2C fast mode. If it is to fast for other I2C devices. deactivate this row.
  display.begin(0x70, 1);                        // I2C adress of the first display

  display.clear(); 
  
  // Autodetect is not working reliable, don't use the following line
  // dht.setup(17);
  // use this instead: 
  dht.setup(DHTPIN, DHTesp::DHT22); // Connect DHT sensor to GPIO 17
  delay(500);

display.print("DHT "); 
delay(pauza);
display.clear(); 
display.print("test"); 
delay(pauza);
display.clear(); 
for (int i = -15; i < 16; i++) 
{
  temperature = i;
  tempe();
  delay(pauzamica);
  display.clear(); 
}
  delay(pauza);
for (int i = 0; i < 100; i=i+2) 
{
  humidity = i;
  humi();
  delay(pauzamica/2);
  display.clear(); 
}
  delay(pauza);
  display.clear(); 
  display.print("real");
  delay(pauza);
  display.clear();  
}

void loop() {  
humidity = dht.getHumidity();
temperature = dht.getTemperature();  
  Serial.println(" ");
  Serial.print("t = ");
  Serial.print(temperature);
  Serial.print("C h = ");
  Serial.print(humidity);
  Serial.println("%"); 
tempe();
delay(pauza);
display.clear(); 
humi();
delay(pauza);
display.clear(); 
}  //end main loop

void tempe()
{
if (temperature >= 0)
 {
  if (temperature < 10) display.print(F(" "));
  display.print(temperature);
  display.print("%C"); 
 }
else
 {
  display.print("-");
  display.print(-temperature);
  if (-temperature < 10)
  display.print("%C"); 
  else
  display.print("C");  
 }
}
void humi()
{
  if (humidity >= 100) humidity = 99;
  if (humidity < 10) display.print(F(" "));
  display.print(humidity);
  display.print("%o"); 
}
