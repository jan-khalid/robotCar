#define echoPin 12
#define trigPin 11

void setup() {
 Serial.begin (9600);
 pinMode(echoPin, INPUT);
 pinMode(trigPin, OUTPUT);
}

void loop() {
 long duration, distance_in_cm;
 // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 
 duration = pulseIn(echoPin, HIGH);
 distance_in_cm = (duration/2) / 29.1;

 Serial.println(distance_in_cm);
 
 delay(1000);
}
