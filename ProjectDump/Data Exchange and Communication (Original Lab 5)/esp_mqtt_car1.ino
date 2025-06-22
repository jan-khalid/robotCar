/*
 * Publish "car_1/test"
 * Suscribe "car_2/#"
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void mqtt_callback(char* topic, byte* payload, unsigned int len);
bool setup_wifi();
void reconnect();

////// wifi network information ///////////////
// MODIFY THE FOLLOWING INFORMATION TO YOUR OWN NETWORK INFORMATION
////////////////////////////////////////////////
String ssid = "IDP-wifi";
String password = "Admin1234";
///////////////////////////////////////////////

/////// MQTT topic information ////////////////
// MAKE SURE YOU USE THE RIGHT GROUP NAME AND CAR ID
char* my_topic = "T1_car_1/test";
char* message = "This is car_1";
char* sub_topic = "T1_car_2/#";
///////////////////////////////////////////////

/////// declare MQTT client ////////////////////
// VERIFY THE MQTT SERVER IP ADDRESS ACCORDING TO THE LAB INSTRUCTIONS
////////////////////////////////////////////////
const IPAddress mqtt_server(5, 196, 95, 208);
WiFiClient esp_client;
PubSubClient client(mqtt_server, 1883, mqtt_callback, esp_client);
////////////////////////////////////////////////

void setup() {
 
  Serial.begin(115200);
  Serial.println(); // clear some mojibake from Serial

  setup_wifi();   // setup wifi access
  
  Serial.println("Listening...");
}

void loop() {

  /* connect to MQTT broker if not yet done so */
  if (!client.connected()) {
    reconnect();
  }

  /* publish to MQTT broker */
  client.publish(my_topic, message);
  Serial.println("Publish message " + (String) message + " to topic " + (String) my_topic);
  delay(1000);
  
  /* receive subscribed MQTT topics if any */
  client.loop();
}

// this method is called when a message is received
// char* topic is the subscribed topic
// byte* payload is the message
// len is the length of the message
void mqtt_callback(char* topic, byte* payload, unsigned int len) {  
  Serial.print(F("Subscribed Topic: "));
  Serial.print(topic);
  Serial.print(F("\tPayload: "));
  for (unsigned int i = 0; i < len; i++) {
    Serial.print((char) payload[i]);
  }
  Serial.println();
}

// connect to the MQTT broker
// subscribe to topic of interest
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    
    Serial.print(F("Attempting MQTT connection..."));
    
    // Create a random client ID
    String clientId = "Smart_Car-";
    clientId += String(random(0xffff), HEX);
    
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");

      // subscribe topic of interest
      client.subscribe(sub_topic);
    } 
    else { // connection failed
      Serial.print(F("failed, rc="));
      Serial.print(client.state());
      Serial.println(F(" try again in 5 seconds"));
      Serial.print(F("ERROR,Connection failed"));   
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

bool setup_wifi() {
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);
  
  WiFi.begin(ssid.c_str(), password.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    
    delay(500);
    Serial.print(F("."));
  }

  randomSeed(micros());
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
  Serial.println(F("CONNECTED"));
  return true;
}
