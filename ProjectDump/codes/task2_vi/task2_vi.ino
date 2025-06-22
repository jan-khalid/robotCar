
#define Sclk 46 //--- connect this to the display module CLK pin (Serial Clock)

#define Mosi 47 //--- connect this to the display module DIN pin (Serial Data)

#define Rst  48 //--- connect this to the display module RES pin (Reset)

#define Dc   48 //--- connect this to the display module D/C  pin (Data or Command)

#define Cs   50 //--- connect this to the display module CS  pin (Chip Select)

#include <Adafruit_SSD1331.h>

Adafruit_SSD1331 display = Adafruit_SSD1331(Cs, Dc, Mosi, Sclk, Rst);

//////////////////////////////////////////////////////
//motor driver LM298 control pin
int pin1R = 8;
int pin2R = 9;
int pin1L = 10;
int pin2L = 11;

///////////////////////////////////////////////////////
// Photo Diode
#define photoPinAnalogR  A8//Photo Right
#define photoPinR 38  //Photo Right
#define photoPinAnalogL  A9//Photo Left
#define photoPinL  39  //Photo Left

bool photoR = 0; //right
bool photoL = 0; //left
int photoAnalogR = 0; //right
int photoAnalogL = 0; //left


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  

  Serial.print("|PR = ");
  Serial.print(photoR);
  Serial.print(",");
  Serial.print(photoAnalogR);
  Serial.print("|PL = ");
  Serial.print(photoL);
  Serial.print(",");
  Serial.print(photoAnalogL);
  Serial.print("|power = ");
  Serial.println("");
  followLight();
}

void followLight(){
  photoR     = digitalRead(photoPinR);
  photoL     = digitalRead(photoPinL);
  if(photoR == LOW and photoL==LOW)
    forwardCar();
  else if(photoL==LOW and photoR == HIGH)
    forwardR();
  else if(photoL==HIGH and photoR == LOW)
    forwardL();
  else
    stopCar();
  
}

    
void forwardCar() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}

void forwardR() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
}

void forwardL() {
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}


void stopCar() {
  stopL();
  stopR();
}

void stopL() {
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 0);
}

void stopR() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 0);
}
