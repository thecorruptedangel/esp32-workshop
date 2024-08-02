#include "BluetoothSerial.h"

BluetoothSerial ESP_BT;  // Object for Bluetooth

void setup() {
  Serial.begin(115200);
  ESP_BT.begin("ESP32_Test");  // Bluetooth device name
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {
  if (ESP_BT.available()) {  // Check if we receive anything from Bluetooth
    char incomingChar = ESP_BT.read();  // Read the received data
    Serial.print(incomingChar);  // Print the received data
    ESP_BT.print(incomingChar);  // Send the received data back to the smartphone
  }
}
