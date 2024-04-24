#include <Arduino.h>
#include "pins_arduino.h"
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YourESP32AP"; // Set your AP name here
const char* password = "12345678"; // Set your AP password here

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hello, this server is working!");
}

void setup() {
  Serial.begin(115200);

  // Create Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot); // Define the handling function for the root URL
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
