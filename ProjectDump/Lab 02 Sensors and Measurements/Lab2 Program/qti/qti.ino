const int qtiPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  // charge up the capacitor
  pinMode(qtiPin, OUTPUT);
  digitalWrite(qtiPin, HIGH);
  delayMicroseconds(230);

  // prepare to read the voltage
  pinMode(qtiPin, INPUT);
  digitalWrite(qtiPin, LOW);
  delayMicroseconds(230);

  byte black_or_white = digitalRead(qtiPin);
  if (black_or_white == HIGH)
    Serial.println("black");
  else
    Serial.println("white");
    
  delay(100);
}
