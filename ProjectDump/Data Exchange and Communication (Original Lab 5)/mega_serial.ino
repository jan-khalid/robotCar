/*
 * Communication between Arduino Mega and ESP8266
 */
 
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  // Serial.println() outputs to Serial Monitor
  // Serial1.println() outputs to ESP8266
  
  Serial.println(F("To ESP8266: Hello! I am Mega"));
  Serial1.println(F("Hello! I am Mega."));
    
  String serial_str;
  while (Serial1.available()) {
    serial_str = Serial1.readStringUntil('\n');
    Serial.print(F("Message From ESP8266: "));
    Serial.println(serial_str);
  }
  
  delay(5000);
}
