#include <Arduino.h>
#include "RTClib.h"

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; 
RTC_DS3231 rtc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  if(!rtc.begin())
  {
    Serial.println("rtc, 見つけられない");
  }
  if (rtc.lostPower())
  {
    Serial.println("RTC lost the power");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  Serial.println(now.hour(), DEC);
}