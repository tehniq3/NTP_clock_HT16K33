// https://www.hackster.io/alankrantas/esp8266-ntp-clock-on-ssd1306-oled-arduino-ide-35116e
// v.1 - moved info on HT16k33 4 digit 14-segment display by Nicu FLORICA (niq_ro)

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h>                                          // needed for the DS3231 and HT16K33
#include "NoiascaHt16k33.h"                                // include the noiasca HT16K33 library - download from http://werner.rothschopf.net/

Noiasca_ht16k33_hw_14 display = Noiasca_ht16k33_hw_14();   // 14 segment - Present time

const char *ssid = "bbk2"; // your wifi name and password
const char *pw   = "internet2";
const long timezoneOffset = 2 * 60 * 60; // ? hours * 60 * 60

const char          *ntpServer  = "pool.ntp.org"; // change it to local NTP server if needed
const unsigned long updateDelay = 900000;         // update time every 15 min
const unsigned long retryDelay  = 5000;           // retry 5 sec later if time query failed
//const String        weekDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const String        weekDays[7] = {"Dum ", "Luni", "Mar ", "Mie ", "Joi ", "Vin ", "Sam "};

unsigned long lastUpdatedTime = updateDelay * -1;
unsigned int  second_prev = 0;
bool          colon_switch = false;

ESP8266WiFiMulti WiFiMulti;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer);
#include <DS3231.h> // For the DateTime object, originally was planning to use this RTC module: https://www.arduino.cc/reference/en/libraries/ds3231/

// Alarm State
// * DateTime objects cannot be modified after creation, so I get the current DateTime and use it to create the default 7AM alarm *
DateTime today = DateTime(timeClient.getEpochTime());
String oravara = "on"; // Default to having the alarm enabled

WiFiServer server(80); // Set web server port number to 80

// Web Host
String header; // Variable to store the HTTP request
unsigned long currentTime = millis(); // Current time
unsigned long previousTime = 0; // Previous time
const long timeoutTime = 2000; // Define timeout time in milliseconds (example: 2000ms = 2s)


void setup() {

  Serial.begin(9600);
  Wire.begin();                                  // start the I2C interface
  Wire.setClock(400000);                         // optional: activate I2C fast mode. If it is to fast for other I2C devices. deactivate this row.
  display.begin(0x70, 1);                        // I2C adress of the first display

  Serial.println("Connecting to WiFi...");
  WiFiMulti.addAP(ssid, pw); // multiple ssid/pw can be added
  while (WiFiMulti.run() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("\nConnected.");

   display.clear();

  timeClient.setTimeOffset(timezoneOffset);
  timeClient.begin();

}

void loop() {

  if (WiFiMulti.run() == WL_CONNECTED && millis() - lastUpdatedTime >= updateDelay) {
    bool updated = timeClient.update();
    if (updated) {
      Serial.println("NTP time updated.");
      lastUpdatedTime = millis();
    } else {
      Serial.println("Failed to update time. Waiting for retry...");
      lastUpdatedTime = millis() - updateDelay + retryDelay;
    }
  } else {
    if (WiFiMulti.run() != WL_CONNECTED) Serial.println("WiFi disconnected!");
  }

  unsigned long t = millis();

  unsigned int year = getYear();
  unsigned int month = getMonth();
  unsigned int day = getDate();
  unsigned int hour = timeClient.getHours();
  unsigned int minute = timeClient.getMinutes();
  unsigned int second = timeClient.getSeconds();
  String weekDay = weekDays[timeClient.getDay()];

  if (second != second_prev) colon_switch = !colon_switch;
/*
  String fYear = String(year);
//  String fDate = (month < 10 ? "0" : "") + String(month) + "/" + (day < 10 ? "0" : "") + String(day);
  String fDate = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month)  ;
  String fTime = (hour < 10 ? "0" : "") + String(hour) + (colon_switch ? ":" : " ") + (minute < 10 ? "0" : "") + String(minute);

  u8x8.setFont(u8x8_font_lucasarts_scumm_subtitle_o_2x2_f);
  u8x8.drawString(1, 0, strcpy(new char[fDate.length() + 1], fDate.c_str()));
  u8x8.setFont(u8x8_font_pxplusibmcga_f);
  u8x8.drawString(12, 0, strcpy(new char[fYear.length() + 1], fYear.c_str()));
  u8x8.setFont(u8x8_font_victoriamedium8_r);
  u8x8.drawString(12, 1, strcpy(new char[weekDay.length() + 1], weekDay.c_str()));
  u8x8.setFont(u8x8_font_inb33_3x6_f);
  u8x8.drawString(1, 2, strcpy(new char[fTime.length() + 1], fTime.c_str()));
*/
  display.clear();
      if (hour < 10) display.print(F("0"));
      display.print(hour);
      if (millis()/1000%2 == 0)
      display.print(F("."));
      if (minute < 10) display.print(F("0"));
      display.print(minute);

  second_prev = second;

  int diff = millis() - t;
  delay(diff >= 0 ? (500 - (millis() - t)) : 0);

}  //end main loop

unsigned int getYear() {
  time_t rawtime = timeClient.getEpochTime();
  struct tm * ti;
  ti = localtime (&rawtime);
  unsigned int year = ti->tm_year + 1900;
  return year;
}

unsigned int getMonth() {
  time_t rawtime = timeClient.getEpochTime();
  struct tm * ti;
  ti = localtime (&rawtime);
  unsigned int month = ti->tm_mon + 1;
  return month;
}

unsigned int getDate() {
  time_t rawtime = timeClient.getEpochTime();
  struct tm * ti;
  ti = localtime (&rawtime);
  unsigned int month = ti->tm_mday;
  return month;
}
