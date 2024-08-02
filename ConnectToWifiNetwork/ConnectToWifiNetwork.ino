#include <WiFi.h>  // Include the WiFi library for ESP32 boards

// Define the SSID and password for the WiFi network
const char* ssid = "Nothing";      // WiFi network name
const char* password = "123456789"; // WiFi network password

void setup() {
  Serial.begin(115200);  // Initialize serial communication at a baud rate of 115200
  delay(1000);  // Wait for a second to ensure everything is ready
  Serial.println("Connecting to WiFi");  // Print a message to the Serial Monitor

  WiFi.begin(ssid, password);  // Attempt to connect to the specified WiFi network
  
  // Loop until the WiFi connection is established
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);  // Wait half a second
    Serial.print(".");  // Print a dot to indicate connection attempts
  }

  // Once connected, print a confirmation message
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");  // Print the IP address assigned to the ESP32
  Serial.println(WiFi.localIP()); // Display the local IP address
}

void loop() {
  // The loop function is empty because this program only connects to WiFi once in the setup
}
