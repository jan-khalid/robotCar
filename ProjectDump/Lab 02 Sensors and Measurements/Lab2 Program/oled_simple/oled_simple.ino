
#define sclk 13 //--- connect this to the display module CLK pin (Serial Clock)

#define mosi 11 //--- connect this to the display module DIN pin (Serial Data)

#define rst  9 //--- connect this to the display module RES pin (Reset)

#define dc   8 //--- connect this to the display module D/C  pin (Data or Command)

#define cs   10 //--- connect this to the display module CS  pin (Chip Select)



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

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

int counter = 0;

void setup()
{
  Serial.begin(9600);

  display.begin();
  display.fillScreen(BLACK);
  tftPrintTest();
  delay(2000);  
  display.fillScreen(BACKGROUND);
  display.setCursor(0,0);
}

void loop() {
  
  display.fillScreen(BLACK);
  delay(250);
  display.fillScreen(WHITE);
  delay(250);
  display.fillScreen(BLACK);
  display.setTextColor(WHITE);  
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(counter);
  counter++;
  delay(1500);

}


void tftPrintTest() {
  display.fillScreen(BLACK);
  display.setCursor(15, 5);
  display.setTextColor(WHITE);  
  display.setTextSize(2);
  display.println("HKUEEE");
  display.setCursor(0, 25);
  display.setTextColor(CYAN);
  display.setTextSize(2);
  display.println("IDP 2018");
  display.setCursor(15, 50);
  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.println("Lab 2");
  delay(1500);

}
