/*
   Communication between Arduino Mega and ESP8266
*/

void setup() {
  Serial.begin(115200);
}

void loop() {    
  String serial_str;
  while (Serial.available()) {
    serial_str = Serial.readStringUntil('\n');
    Serial.print("Reply to \"" + serial_str + "\": ");
    Serial.println(F(" I am ESP8266!"));
    
  }
  delay(50);
}
