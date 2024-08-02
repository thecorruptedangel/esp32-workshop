#include <esp_now.h>
#include <WiFi.h>

// Structure for message
typedef struct struct_message {
    char a[32];
    int b;
} struct_message;

// Create a struct_message to hold data
struct_message message;

// MAC address of the peer
uint8_t peerAddress[] = {0x2C, 0xBC, 0xBB, 0x0E, 0x00, 0xC4};

// Callback when data is sent
void onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    
}

// Callback when data is received
void onDataReceive(const esp_now_recv_info *esp_now_info, const uint8_t *incomingData, int len) {
    memcpy(&message, incomingData, sizeof(message));
    Serial.print("RECEIVER: ");
    Serial.println(message.a);
}

void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Register callback functions
    esp_now_register_send_cb(onDataSent);
    esp_now_register_recv_cb(onDataReceive);

    // Register peer
    esp_now_peer_info_t peerInfo;
    memset(&peerInfo, 0, sizeof(peerInfo));
    memcpy(peerInfo.peer_addr, peerAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }

    // Print when the device is ready
    Serial.println("Device is ready");
}

void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        input.trim(); // Remove any extra whitespace
        if (input.length() > 0) {
            input.toCharArray(message.a, 32);
            message.b = input.length(); // Example: send length of the message

            // Send message
            esp_now_send(peerAddress, (uint8_t *)&message, sizeof(message));
            Serial.print("SENDER: ");
            Serial.println(message.a);
        }
    }

    delay(100); // Small delay to avoid overloading the loop
}
