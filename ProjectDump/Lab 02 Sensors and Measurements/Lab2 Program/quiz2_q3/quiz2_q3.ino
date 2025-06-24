
#define Sclk 13 //--- connect this to the display module CLK pin (Serial Clock)

#define Mosi 11 //--- connect this to the display module DIN pin (Serial Data)

#define Rst  9 //--- connect this to the display module RES pin (Reset)

#define Dc   8 //--- connect this to the display module D/C  pin (Data or Command)

#define Cs   10 //--- connect this to the display module CS  pin (Chip Select)



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

void setup()
{
  display.begin();
  display.setCursor(91,57);
  display.setTextColor(GREEN);
  display.setTextSize(1);
  display.print("*");
}
