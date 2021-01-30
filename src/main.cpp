#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ArduinoJson.h>

const char *ssid = "***";
const char *password = "***";

const uint16_t kIrLed = 4;
IRsend irsend(kIrLed);

int sound_digital = 4;
int sound_analog = 0;

bool flag = false;

void setup()
{
  Serial.begin(115200);

  pinMode(sound_digital, INPUT);
  pinMode(sound_digital, INPUT);

  irsend.begin();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print("Connecting.." + WiFi.status());
  }
}

void SoundCheckInviroment()
{
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  if (val_analog > 500)
  {
    Serial.println(val_analog);

    HTTPClient http;

    String url = "http://burglaralarm.persianprogrammer.com/ManageNotification/CheckCamera?serial=d6ac5b88-35e9-461f-b911-2f68d4cb9c44";
    http.begin(url);

    int httpCode = http.GET();

    if (httpCode > 0)
    {
      flag = (bool)http.getString();

      if (flag == true)
      {
        irsend.sendNEC(0x20DF10EF);
      }
    }
    http.end();
  }
}

void ControllerTV()
{
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  if (val_analog > 500)
  {
    Serial.println(val_analog);

    HTTPClient http;

    String url = "http://burglaralarm.persianprogrammer.com/ManageNotification/CheckCamera?serial=d6ac5b88-35e9-461f-b911-2f68d4cb9c44";
    http.begin(url);

    int httpCode = http.GET();

    if (httpCode > 0)
    {
      flag = (bool)http.getString();

      if (flag == true)
      {
        irsend.sendNEC(0x20DF10EF);
      }
    }
    http.end();
  }
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    SoundCheckInviroment();

    if (flag == true)
    {
    }
  }
}
