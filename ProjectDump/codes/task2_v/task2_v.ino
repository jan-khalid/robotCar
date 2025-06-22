
#define Sclk 50 //--- connect this to the display module CLK pin (Serial Clock)

#define Mosi 49 //--- connect this to the display module DIN pin (Serial Data)

#define Rst  47 //--- connect this to the display module RES pin (Reset)

#define Dc   46 //--- connect this to the display module D/C  pin (Data or Command)

#define Cs   48 //--- connect this to the display module CS  pin (Chip Select)

int pin1R = 8;
int pin2R = 9;
int pin1L = 10;
int pin2L = 11;

#define echoPin 6
#define trigPin 7


// Color definitions

#define  BLACK           0x0000

#define BLUE            0x0006

#define RED             0xF800

#define GREEN           0x07E0

#define CYAN            0x07FF

#define MAGENTA         0xF81F

#define YELLOW          0xFFE0  

#define WHITE           0xFFFF

#define BACKGROUND      0x0000


#include <Adafruit_SSD1331.h>

Adafruit_SSD1331 display = Adafruit_SSD1331(Cs, Dc, Mosi, Sclk, Rst);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
int value = 0;
void setup()
{
  Serial.begin(9600);

  display.begin();
  display.fillScreen(BLACK);
  //tftPrintTest();
  //delay(2000);  
  display.fillScreen(BACKGROUND);
  display.setCursor(0,0);
}

void loop() {
  long duration, distance_in_cm;
   // read the value at analog input
   value = analogRead(analogInput);
   vin = (value * 5.0) / 1024.0; // see text
   if (vin<0.01) {
   vin=0.0; }      //statement to remove undesired reading!

  display.fillScreen(BLACK);
  display.setCursor(0, 1);
  display.setTextColor(WHITE);  
  display.setTextSize(2);
  //display.println("INPUT V= ");
  //Serial.print("INPUT V= ");
  display.setCursor(0, 25);
  //display.print(vin);
  //display.println(vin);

  

  digitalWrite(trigPin, LOW); 
  //delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  distance_in_cm = (duration/2) / 29.1;
  Serial.println("Distance_in_cm: ");
  Serial.println(distance_in_cm);

  if(distance_in_cm<20){
    stopCar();
    delay(1000);
    
      
    display.fillScreen(BLACK);
    display.setCursor(0, 1);
    display.setTextColor(WHITE);  
    display.setTextSize(2);
    
    //Serial.print("INPUT V= ");
    display.setCursor(0, 25);
    display.println("INPUT V= ");
    Serial.println(vin);
    delay(100);
      
   
    
  }else{
      forwardCar();
      display.fillScreen(BLACK);
      display.setCursor(0, 1);
      display.setTextColor(WHITE);  
      display.setTextSize(2);
      display.println("INPUT V= ");
      display.print(vin);
    }
  
  

}



void forwardCar() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}


void stopCar() {
  stopL();
  stopR();
}

void stopR() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 0);
}

void stopL() {
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 0);
}
void tftPrintTest() {

  
  display.fillScreen(BLACK);
  display.setCursor(0, 1);
  display.setTextColor(WHITE);  
  display.setTextSize(2);
  display.println("INPUT V= ");
  display.setCursor(0, 25);
  display.print("Ready to measure");
  //display.print(vin);
  //delay(500);

}

void backwardCar() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 1);
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 1);
}
