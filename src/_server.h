#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "MIWIFI_2G_aYUz";
const char* password = "0123456789j";

bool serverStarted = false;

void setupServer() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  server.on("/ledsname", []() {
    server.send(200, "text/plain", "ReactiveLeds");
  });

  server.begin();
  serverStarted = true;
}

void updateServer() {
  if (serverStarted)
    server.handleClient();
}