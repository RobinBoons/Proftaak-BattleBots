#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>
#include "FastLED.h"

#define NUM_LEDS 144
#define DATA_PIN 5
#define BRIGHTNESS  255

char ssid[] = "12connect";
int wifiStatus = WL_IDLE_STATUS;
WiFiClient client;
IPAddress server(145, 85, 4, 91);
PubSubClient mqttClient(client);

char mqttUser[] = "i339322_timojansen";
char mqttPass[] = "Xjr1MGsdYEKtJ5";
String mqttClientId = "arduino-";
String subscribeTopic = "private/i339322_timojansen/#";

CRGB leds[NUM_LEDS];
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
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       };

void setup() {
  delay(1000);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  updateMatrix();
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
  String payloadString = String((char*)payload);
  Serial.println(payloadString);
}

void updateMatrix() {
  for (int i = 0; i <= NUM_LEDS; i++) {
    if (bitMap[i] == 1) {
      leds[i] = CRGB::Red;
    }
    else if (bitMap[i] == 2) {
      leds[i] = CRGB::Green;
    }
    else if (bitMap[i] == 3) {
      leds[i] = CRGB::Blue;
    }
    else if (bitMap[i] == 4) {
      leds[i] = CRGB::Yellow;
    }
    else if (bitMap[i] == 5) {
      leds[i] = CRGB::Cyan;
    }
    else if (bitMap[i] == 6) {
      leds[i] = CRGB::Purple;
    }
    else if (bitMap[i] == 7) {
      leds[i] = CRGB::Orange;
    }
    else if (bitMap[i] == 8) {
      leds[i] = CRGB::Brown;
    }
    else if (bitMap[i] == 9) {
      leds[i] = CRGB::White;
    }
    else if (bitMap[i] == 0) {
      leds[i] = CRGB::Black;
    }
  }

  FastLED.show();
}

String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
  }
  return result;
}
