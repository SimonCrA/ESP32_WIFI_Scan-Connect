#include <Arduino.h>
#include <WiFi.h>

int PIN_led = 13;
const char* ssid = "noShar3";
const char* password = "holacomoestas";

String translateEncryptionType(wifi_auth_mode_t encryptionType) {

  switch (encryptionType) {
    
    case (WIFI_AUTH_OPEN):
      return "Open";
    case (WIFI_AUTH_WEP):
      return "WEP";
    case (WIFI_AUTH_WPA_PSK):
      return "WPA_PSK";
    case (WIFI_AUTH_WPA2_PSK):
      return "WPA2_PSK";
    case (WIFI_AUTH_WPA_WPA2_PSK):
      return "WPA_WPA2_PSK";
    case (WIFI_AUTH_WPA2_ENTERPRISE):
      return "WPA2_ENTERPRISE";
  }

}

void scanNetworks() {

  int numberOfNetworks = WiFi.scanNetworks();

  Serial.print("Number of networs found: ");
  Serial.println(numberOfNetworks);

  for (int i = 0; i < numberOfNetworks; i++) {
    
    Serial.print("Network Name: ");
    Serial.println(WiFi.SSID(i));

    Serial.print("Signal Strength: ");
    Serial.println(WiFi.RSSI(i));

    Serial.print("MAC Address: ");
    Serial.println(WiFi.BSSIDstr(i));

    Serial.print("Encryption Type: ");
    String encryptionTypeDescription = translateEncryptionType(WiFi.encryptionType(i));
    Serial.println(encryptionTypeDescription);
    Serial.println("---------------------------");

  }
  
}

void connectToNetwork() {

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    
    delay(1000);
    Serial.println("Establishing connection to WiFi...");
    digitalWrite(PIN_led, LOW);
  }

  Serial.println("Connected to network!");
  digitalWrite(PIN_led, HIGH);

}

void setup() {
  
  Serial.begin(115200);

  pinMode(PIN_led, OUTPUT);

  scanNetworks();
  connectToNetwork();

  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());

  WiFi.disconnect(true);
  Serial.println(WiFi.localIP());

}

void loop() {
  
}