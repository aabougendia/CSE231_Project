#include "ManualControl.h"

WebServer server(80);
ManualState man_state = DRV_STOP;

void handlePress();
void handleRelease();
void handleServo();

void Wifi_Init(){
  // Serial.begin(115200);
  // delay(1000); // Give serial time to initialize
  
  // Initialize LEDs
  // pinMode(ledLeft, OUTPUT);
  // pinMode(ledRight, OUTPUT);
  // pinMode(ledCenter, OUTPUT);
  
  // Start with all LEDs off except center
  // digitalWrite(ledLeft, LOW);
  // digitalWrite(ledRight, LOW);
  // digitalWrite(ledCenter, HIGH); // Center LED on at startup

  // Start WiFi AP with more reliable settings
  // Serial.println("Starting WiFi AP...");
  
  // Configure WiFi AP settings
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IPAddress(192,168,4,1), IPAddress(192,168,4,1), IPAddress(255,255,255,0));
  
  // Start AP with explicit parameters:
  // SSID: "ESP32_LED_Test"
  // Password: "12345678"
  // Channel: 6 (less crowded)
  // Hidden: false
  // Max connections: 4
  bool apStarted = WiFi.softAP("ESP32_LED_Test", "12345678", 6, false, 4);
  
  if (!apStarted) {
    Serial.println("Failed to start AP!");
    // Blink center LED rapidly to indicate failure
    // while(1) {
      // digitalWrite(ledCenter, !digitalRead(ledCenter));
      // delay(200);
    // }
  }

  Serial.println("WiFi AP Started");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("AP MAC address: ");
  Serial.println(WiFi.softAPmacAddress());

  // Server endpoints
  server.on("/servo", handleServo);
  server.begin();
  Serial.println("HTTP server started");
}

void Drive_Init(){
  Serial.begin(115200);
  delay(1000); // Wait for serial
  
  // Start WiFi AP
  Serial.println("Starting AP...");
  bool apStarted = WiFi.softAP("ESP32_Control", "12345678", 6);
  
  if (!apStarted) {
    while(1) {
      Serial.println("AP FAILED! Check hardware.");
    }
  }
  
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  // digitalWrite(ledS, HIGH); // Steady on = AP ready

  // Server endpoints
  server.on("/press", HTTP_GET, handlePress);
  server.on("/release", HTTP_GET, handleRelease);
  server.begin();
  Serial.println("HTTP server started");
}
void Cam_Init();

void handlePress() {
  String dir = server.arg("dir");
  if (dir == "F") man_state = DRV_FWD;
  else if (dir == "B") man_state = DRV_BWD;
  else if (dir == "L") man_state = DRV_LEFT;
  else if (dir == "R") man_state = DRV_RIGHT;
  server.send(200, "text/plain", "ON");
}

void handleRelease() {
  String dir = server.arg("dir");
  if (dir == "F") man_state = DRV_STOP;
  else if (dir == "B") man_state = DRV_STOP;
  else if (dir == "L") man_state = DRV_STOP;
  else if (dir == "R") man_state = DRV_STOP;
  server.send(200, "text/plain", "OFF");
}

void handleServo() {
  String dir = server.arg("dir");      // "left", "right", or "center"
  String state = server.arg("state");  // "on" or "off"

  // Turn off all direction LEDs first
  // digitalWrite(ledLeft, LOW);
  // digitalWrite(ledRight, LOW);
  // digitalWrite(ledCenter, LOW);

  if (state == "on") {
    if (dir == "left") {
      // digitalWrite(ledLeft, HIGH);
      Serial.println("LEFT movement activated");
    } 
    else if (dir == "right") {
      // digitalWrite(ledRight, HIGH);
      Serial.println("RIGHT movement activated");
    }
    else if (dir == "center") {
      // digitalWrite(ledCenter, HIGH);
      Serial.println("CENTER position activated");
    }
  }
  
  server.send(200, "text/plain", "LEDs: " + dir + "=" + state);
}
