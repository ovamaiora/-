#include <Arduino.h>
#include <RTClib.h>
#include <SPI.h>

RTC_DS1307 rtc;
void setup()
{
  rtc.begin();
  Serial.begin(9600);
  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  if (!rtc.isrunning())
  {
    Serial.print("RTC is NOT running!");
    // rtc.adjust(DateTime(2022, 11, 28, 22, 0, 0));// to set the time manually
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // auto update from computer time
}

void loop()
{
  DateTime now = rtc.now();
  Serial.print("TIME");
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.print("  ");
  Serial.print("DATE");
  Serial.print(" ");
  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.year());
  Serial.println("  ");
  delay(1000);
  //test
}
