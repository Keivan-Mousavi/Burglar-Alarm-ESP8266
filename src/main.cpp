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

void setup()
{
  //#if ESP8266
  //   Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  // #else  // ESP8266
  //   Serial.begin(115200, SERIAL_8N1);
  // #endif // ESP8266

  Serial.begin(115200);

  pinMode(sound_digital, INPUT);
  pinMode(sound_digital, INPUT);

  irsend.begin();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print("Connecting..");
  }
}

void loop()
{
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  if (val_analog > 500)
  {
    irsend.sendNEC(0x20DF10EF);

    Serial.println(val_analog);
    Serial.println(val_digital);

    if (WiFi.status() == WL_CONNECTED)
    {

      HTTPClient http; //Declare an object of class HTTPClient

      http.begin("http://jsonplaceholder.typicode.com/users/1");
      int httpCode = http.GET();

      if (httpCode > 0)
      {
        Serial.println("http : ");
        String payload = http.getString();

        DynamicJsonDocument doc(1024);
        deserializeJson(doc, payload);

        JsonObject json = doc.as<JsonObject>();

        String phone = json[String("phone")];

        Serial.println(phone);

        // Serial.println(payload);           //Print the response payload
      }

      http.end(); //Close connection
    }
  }

  // Serial.println("NEC");
  // irsend.sendNEC(0x20DF10EF);
  // delay(2000);

  // if (WiFi.status() == WL_CONNECTED)
  // { //Check WiFi connection status

  //   HTTPClient http; //Declare an object of class HTTPClient

  //   http.begin("http://jsonplaceholder.typicode.com/users/1"); //Specify request destination
  //   int httpCode = http.GET();                                 //Send the request

  //   if (httpCode > 0)
  //   { //Check the returning code
  //     Serial.println("http : ");
  //     String payload = http.getString(); //Get the request response payload

  //     DynamicJsonDocument doc(1024);
  //     deserializeJson(doc, payload);

  //     JsonObject json = doc.as<JsonObject>();

  //     String phone = json[String("phone")];

  //     Serial.println(phone);

  //     // Serial.println(payload);           //Print the response payload
  //   }

  //   http.end(); //Close connection
  // }

  // delay(2000); //Send a request every 30 seconds
}