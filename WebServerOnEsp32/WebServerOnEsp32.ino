#include <WiFi.h>
#include <WebServer.h>

// Replace these with your network credentials
const char* ssid = "Nothing";
const char* password = "123456789";

// Create an instance of the server
WebServer server(80);

// Function to handle the root URL
void handleRoot() {
  // Send an HTML response with an <h1> tag
  String htmlResponse = "<!DOCTYPE html>"
                        "<html>"
                        "<head><title>ESP32 Web Server</title></head>"
                        "<body>"
                        "<h1>Hello, world!</h1>"
                        "</body>"
                        "</html>";
  server.send(200, "text/html", htmlResponse);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define the root URL handler
  server.on("/", handleRoot);

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}
