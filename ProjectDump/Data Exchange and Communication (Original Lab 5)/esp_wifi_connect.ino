#include <ESP8266WiFi.h>

// network access point and password information
// MODIFY THE FOLLOWING INFORMATION TO YOUR OWN NETWORK INFORMATION
////////////////////////////////////////////////
const char* ssid = "IDP-wifi";
const char* password = "Admin1234";
////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  setup_wifi();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setup_wifi() {

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
