#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

const char* ssid = "Hacked_WiFi";
const char* password = "hacked_password";

WiFiManager wifiManager;

void setup() {
  Serial.begin(115200);
  wifiManager.autoConnect(ssid, password);
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Perform WiFi hacking actions
    // For example, scan for nearby WiFi networks or inject packets
    
    // Scan for nearby WiFi networks
    int numNetworks = WiFi.scanNetworks();
    if (numNetworks > 0) {
      Serial.println("Found " + String(numNetworks) + " WiFi networks");
      for (int i = 0; i < numNetworks; i++) {
        Serial.println(WiFi.SSID(i) + " (" + WiFi.RSSI(i) + " dBm)");
      }
    } else {
      Serial.println("No WiFi networks found");
    }
    
    // Inject packets
    // You can use tools like Wireshark or Scapy to inject packets
    // For example, to send a deauthentication packet:
    // const char* deauthPacket = "80 00 00 00 ff ff ff ff ff ff 00 [MAC_ADDRESS] [MAC_ADDRESS]";
    // WiFi.sendRawPacket(deauthPacket, sizeof(deauthPacket));
    
    delay(5000);
  } else {
    Serial.println("WiFi disconnected");
    wifiManager.startConfigPortal();
  }
}