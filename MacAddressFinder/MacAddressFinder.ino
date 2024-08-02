#include <WiFi.h>

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  // Wait for Serial Monitor to open
  while (!Serial) {
    delay(100);
  }
  
  // Get the MAC address
  String macAddress = WiFi.macAddress();
  
  // Print the MAC address to Serial Monitor
  Serial.println("MAC Address: " + macAddress);
}

void loop() {
  // Nothing to do here
}