#include <WiFi.h>
#include <PubSubClient.h>
#include "FastLED.h"

#define NUM_LEDS 144
#define DATA_PIN 5
#define BRIGHTNESS  64

char ssid[] = "12connect";
int wifiStatus = WL_IDLE_STATUS;
WiFiClient client;
IPAddress server(145, 85, 4, 91);
PubSubClient mqttClient(client);

char mqttUser[] = "i339322_timojansen";
char mqttPass[] = "Xjr1MGsdYEKtJ5";
String mqttClientId = "arduino-";
String subscribeTopic = "private/i339322_timojansen/#";

String payloadString = "";

CRGB leds[NUM_LEDS];
/*
  int bitMap[NUM_LEDS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                        1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1,
                        1, 2, 3, 4, 4, 4, 4, 4, 4, 3, 2, 1,
                        1, 2, 3, 4, 5, 5, 5, 5, 4, 3, 2, 1,
                        1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1,
                        1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1,
                        1, 2, 3, 4, 5, 5, 5, 5, 4, 3, 2, 1,
                        1, 2, 3, 4, 4, 4, 4, 4, 4, 3, 2, 1,
                        1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1,
                        1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

                         0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
                         0, 0, 0, 0, 2, 3, 2, 2, 0, 0, 0, 0,
                         0, 0, 0, 2, 2, 2, 2, 1, 4, 0, 0, 0,
                         0, 0, 0, 2, 4, 1, 1, 2, 2, 0, 0, 0,
                         0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0,
                         0, 0, 1, 3, 2, 2, 4, 2, 2, 2, 0, 0,
                         0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 0, 0,
                         0, 2, 4, 2, 2, 1, 1, 1, 2, 3, 2, 0,
                         0, 2, 2, 2, 2, 2, 2, 3, 1, 1, 1, 0,
                         2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2,
                         0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0

                         8, 8, 8, 8, 0, 0, 0, 0, 8, 8, 8, 8,
                           8, 8, 0, 0, 1, 1, 1, 1, 0, 0, 8, 8,
                           8, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 8,
                           8, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 8,
                           0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                           0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
                           0, 0, 1, 1, 0, 9, 8, 0, 1, 1, 0, 0,
                           0, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 0,
                           8, 0, 9, 9, 9, 0, 0, 9, 9, 9, 0, 8,
                           8, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 8,
                           8, 8, 0, 0, 9, 9, 9, 9, 0, 0, 8, 8,
                           8, 8, 8, 8, 0, 0, 0, 0, 8, 8, 8, 8

  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
  };
*/

void setup() {
  delay(1000);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.begin(57600);
  Serial.println("Arduino C# chat starting..");
  uint8_t mac[6];
  WiFi.macAddress(mac);
  mqttClientId += macToStr(mac);
  Serial.println("Client ID: " + mqttClientId);
  connectWifi();
  if ( wifiStatus != WL_CONNECTED) {
    Serial.println("Could not connect to Wifi");
    while (true);
  }
  else {
    Serial.println("Connected to Wifi");
    delay(5000);
    Serial.println(WiFi.localIP());
  }
  mqttClient.setServer(server, 1883);
  mqttClient.setCallback(callback);
  connectMqtt();
}

void loop() {
  if (wifiStatus != WL_CONNECTED)
    connectWifi();

  while (!mqttClient.connected())
    connectMqtt();

  mqttClient.loop();
  //checkPayload(payloadString);
  kerstboom();
}

void connectWifi() {
  Serial.println("Initializing Wifi...");
  wifiStatus = WiFi.begin(ssid);
}

void connectMqtt() {
  if (!mqttClient.connect((char*) mqttClientId.c_str(), mqttUser, mqttPass))
  {
    Serial.println("ERROR: Cannot connect to MQTT server! Error code: " + String(mqttClient.state()));
  }
  else
  {
    Serial.println("Connected to MQTT");
    if (mqttClient.subscribe((char *)subscribeTopic.c_str())) {
      Serial.println("Subscribed to topic: " + subscribeTopic);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int len) {
  Serial.println("MQTT topic: " + String(topic));
  payloadString = String((char*)payload);
  Serial.println(payloadString);
}

void checkPayload(String j) {
  if (j == "kerstboom") {
    kerstboom();
  }
}

void updateMatrix(int* j){
  for (int i = 0; i <= NUM_LEDS; i++) {
    if (j[i] == 1) {
      leds[i] = CRGB::Red;
    }
    else if (j[i] == 2) {
      leds[i] = CRGB::Green;
    }
    else if (j[i] == 3) {
      leds[i] = CRGB::Blue;
    }
    else if (j[i] == 4) {
      leds[i] = CRGB::Yellow;
    }
    else if (j[i] == 5) {
      leds[i] = CRGB::Cyan;
    }
    else if (j[i] == 6) {
      leds[i] = CRGB::Purple;
    }
    else if (j[i] == 7) {
      leds[i] = CRGB::Orange;
    }
    else if (j[i] == 8) {
      leds[i] = CRGB::Brown;
    }
    else if (j[i] == 9) {
      leds[i] = CRGB::White;
    }
    else if (j[i] == 0) {
      leds[i] = CRGB::Black;
    }
  }

  FastLED.show();
}

void kerstboom() {
  int kerstboom[NUM_LEDS] = {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
                             0, 0, 0, 0, 2, 3, 2, 2, 0, 0, 0, 0,
                             0, 0, 0, 2, 2, 2, 2, 1, 4, 0, 0, 0,
                             0, 0, 0, 2, 4, 1, 1, 2, 2, 0, 0, 0,
                             0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0,
                             0, 0, 1, 3, 2, 2, 4, 2, 2, 2, 0, 0,
                             0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 0, 0,
                             0, 2, 4, 2, 2, 1, 1, 1, 2, 3, 2, 0,
                             0, 2, 2, 2, 2, 2, 2, 3, 1, 1, 1, 0,
                             2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2,
                             0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0
                            };
  int kerstboom2[NUM_LEDS] = {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
                              0, 0, 0, 0, 2, 3, 2, 2, 0, 0, 0, 0,
                              0, 0, 0, 2, 2, 2, 2, 6, 4, 0, 0, 0,
                              0, 0, 0, 2, 4, 6, 6, 2, 2, 0, 0, 0,
                              0, 0, 0, 6, 6, 2, 2, 2, 2, 0, 0, 0,
                              0, 0, 6, 3, 2, 2, 4, 2, 2, 2, 0, 0,
                              0, 0, 2, 6, 6, 2, 2, 2, 2, 2, 0, 0,
                              0, 2, 4, 2, 2, 6, 6, 6, 2, 3, 2, 0,
                              0, 2, 2, 2, 2, 2, 2, 3, 6, 6, 6, 0,
                              2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2,
                              0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0
                             };
  updateMatrix(kerstboom);
  delay(500);
  updateMatrix(kerstboom2);
  delay(500);
}

String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
  }
  return result;
}
