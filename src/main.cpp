#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "_server.h"

void setup() {
  setupServer();
}

void loop() {
  updateServer();
}