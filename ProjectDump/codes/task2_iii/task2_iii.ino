int pin1R = 6;
int pin2R = 7;
int pin1L = 10;
int pin2L = 11;


#define Sclk 50 //--- connect this to the display module CLK pin (Serial Clock)

#define Mosi 49 //--- connect this to the display module DIN pin (Serial Data)

#define Rst  47 //--- connect this to the display module RES pin (Reset)

#define Dc   46 //--- connect this to the display module D/C  pin (Data or Command)

#define Cs   48 //--- connect this to the display module CS  pin (Chip Select)

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


volatile int m = 0;
const int qtiPinL = 44;
const int qtiPinR = 45;
const int qtiFrontR = 42;
const int qtiFrontL = 43;
volatile int counter = 1;
volatile int countery = 1;
volatile bool prev_state = -1;
volatile bool state = -1;

String coord[] = {"0,0","0,1","0,2","0,3","0,4","0,5","1,5","1,4","1,3","1,2","1,1","1,0","2,0","2,1","2,2","2,3","2,4","2,5","3,5","3,4","3,3","3,2","3,1","3,0","4,0","4,1","4,2","4,3","4,4","4,5","5,5","5,4","5,3","5,2","5,1","5,0"};

#define echoPin 49
#define trigPin 48

//Color sensor
//Pin out
#define colorpin_out 26 //brown
#define colorpin_s2 27 //orange
#define colorpin_s3 28 //yellow
#define colorpin_s1 29 //purple
#define colorpin_s0 30 //blue
#define colorpin_LED 31 //green

//parameter
int colorValueC = 0;
int colorValueR = 0;
int colorValueG = 0;
int colorValueB = 0;
int colorCnt = 0; //each loop only detect one color value
int colorCheckCntR = 0; //check several times before detection
int colorCheckCntG = 0;
int colorCheckCntB = 0;
int colorCheckCnt = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  display.begin();
  display.fillScreen(BLACK);
  //tftPrintTest();
  //delay(2000);  
  display.fillScreen(BACKGROUND);
  display.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  

  //forwardCar();
   //black_white();
    ColorInput();
  ColorCheck();
  Serial.println("");
  delay(200);
  black_white();
    
  display.fillScreen(BLACK);
  display.setCursor(0, 1);
  display.setTextColor(WHITE);  
  display.setTextSize(2);
  //display.println("INPUT V= ");
  //Serial.print("INPUT V= ");
  display.setCursor(0, 25);
  display.println(coord[counter]);

}

void black_white(){
     // charge up the capacitor
  pinMode(qtiPinL, OUTPUT);
  digitalWrite(qtiPinL, HIGH);
  pinMode(qtiPinR, OUTPUT);
  digitalWrite(qtiPinR, HIGH);
  pinMode(qtiFrontL, OUTPUT);
  digitalWrite(qtiFrontL, HIGH);
  pinMode(qtiFrontR, OUTPUT);
  digitalWrite(qtiFrontR, HIGH);
  delayMicroseconds(230);

  // prepare to read the voltage
  pinMode(qtiPinL, INPUT);
  digitalWrite(qtiPinL, LOW);
  pinMode(qtiPinR, INPUT);
  digitalWrite(qtiPinR, LOW);
  pinMode(qtiFrontL, INPUT);
  digitalWrite(qtiFrontL, LOW);
  pinMode(qtiFrontR, INPUT);
  digitalWrite(qtiFrontR, LOW);
  delayMicroseconds(230);

  if(state != -1){
    prev_state = state;
  }
  

  byte black_or_whiteL = digitalRead(qtiPinL);
  byte black_or_whiteR = digitalRead(qtiPinR);

  byte black_or_whiteLF = digitalRead(qtiFrontL);
  byte black_or_whiteRF = digitalRead(qtiFrontR);
  
  if( counter % 5 == 0 and counter % 2 == 0){
    Serial.println("Turning Right");
    m += 1;
    turnCarOnsiteR();
    delay(1400);
    forwardCar();
    delay(300);
    turnCarOnsiteR();
    delay(1400);
    counter = m*2 + 1;
    Serial.println("m:");
    Serial.println(m);
  }
   
  else if( counter % 5 == 0 and counter % 2 == 1){
    Serial.println("Turning Left");
    m += 1;
    turnCarOnsiteL();
    Serial.println("1");
    delay(1400);
    forwardCar();
    delay(300);
    Serial.println("2");
    turnCarOnsiteL();
    Serial.println("31111");
    delay(1400);
    Serial.println("3567");
    counter = m*2 + 1;
    Serial.println("Turning Left out");
    Serial.println("m:");
    Serial.println(m);
  }
  
  if(black_or_whiteL==LOW and black_or_whiteR==LOW){
    //Serial.println("White");
    state = 1;
  }else if(black_or_whiteL==HIGH and black_or_whiteR==HIGH){
    //counter += 1;
    //Serial.println("Black");
    state = 0;
  }
  Serial.println(counter);
      Serial.println("m:");
    Serial.println(m);
  if(state==1 and prev_state==0){
    counter += 1;
    
    //state = 0;
  }

  if(prev_state == state){
    stopCar();
    forwardCar();
  }

}


void forwardR() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
}
void backwardR() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 1);
}
void stopR() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 0);
}
void forwardL() {
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}
void backwardL() {
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 1);
}
void stopL() {
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 0);
}
void turnCarR() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}
void turnCarL() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 0);
}
void turnCarL_Backward() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 1);
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 0);
}
void turnCarR_Backward() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 1);
}
void turnCarOnsiteL() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 1);
}
void turnCarOnsiteR() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 1);
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}
void forwardCar() {
  digitalWrite(pin1R, 1);
  digitalWrite(pin2R, 0);
  digitalWrite(pin1L, 1);
  digitalWrite(pin2L, 0);
}
void backwardCar() {
  digitalWrite(pin1R, 0);
  digitalWrite(pin2R, 1);
  digitalWrite(pin1L, 0);
  digitalWrite(pin2L, 1);
}
void stopForwardCar() {
  backwardCar();
  delay(150);
  stopL();
  stopR();
}
void stopBackwardCar() {
  forwardCar();
  delay(100);
  stopL();
  stopR();
}
void stopTurnCarOnsiteL() {
  turnCarOnsiteR();
  delay(100);
  stopL();
  stopR();
}
void stopTurnCarOnsiteR() {
  turnCarOnsiteL();
  delay(100);
  stopL();
  stopR();
}
void stopCar() {
  stopL();
  stopR();
}

void ColorInput() {
  if (colorCnt == 0) {
    //read Clear value
    colorValueC = pulseIn(colorpin_out, LOW);
    //Set Red filter
    digitalWrite(colorpin_s2, 0);
    digitalWrite(colorpin_s3, 0);
    colorCnt++;
  }
  else if (colorCnt == 1) {
    //read Red value
    colorValueR = pulseIn(colorpin_out, LOW);
    //Set Blue filter
    digitalWrite(colorpin_s2, 0);
    digitalWrite(colorpin_s3, 1);
    colorCnt++;
  }
  else if (colorCnt == 2) {
    //read Blue value
    colorValueB = pulseIn(colorpin_out, LOW);
    //Set Green filter
    digitalWrite(colorpin_s2, 1);
    digitalWrite(colorpin_s3, 1);
    colorCnt++;
  }
  else {
    //read Green value
    colorValueG = pulseIn(colorpin_out, LOW);
    //Set Clear filter
    digitalWrite(colorpin_s2, 1);
    digitalWrite(colorpin_s3, 0);
    colorCnt = 0;
  }
  Serial.print(" colorCRBG= ");
  Serial.print(colorValueC);
  Serial.print(" ");
  Serial.print(colorValueR);
  Serial.print(" ");
  Serial.print(colorValueB);
  Serial.print(" ");
  Serial.print(colorValueG);
  Serial.print(" ");
}
void ColorCheck() {
  //Check Red Color
  if ((1000 < colorValueC  ) &&
      (1000 < colorValueR  ) &&
      (1000 < colorValueB  ) &&
      (1000 < colorValueG )) {
    colorCheckCntR++;
  } else {
    colorCheckCntR = 0;
  }
  //Continous detection before notification
  if (colorCheckCntR > colorCheckCnt) {
    Serial.print(" Red is detected. ");
    colorCheckCntR = colorCheckCnt;
    stopCar();
    delay(5000);
  }
  //Check Green Color
  if ((1 < colorValueC && colorValueC < 12) &&
      (11 < colorValueR && colorValueR < 22) &&
      (10 < colorValueB && colorValueB < 17) &&
      (6 < colorValueG && colorValueG < 16)) {
    colorCheckCntG++;
  } else {
    colorCheckCntG = 0;
  }
  //Continous detection before notification
  if (colorCheckCntG > colorCheckCnt) {
    Serial.print(" Green is detected. ");
    colorCheckCntG = colorCheckCnt;
  }
  //Check Blue Color
  if ((3 < colorValueC && colorValueC < 7) &&
      (17 < colorValueR && colorValueR < 26) &&
      (6 < colorValueB && colorValueB < 10) &&
      (8 < colorValueG && colorValueG < 18)) {
    colorCheckCntB++;
  } else {
    colorCheckCntB = 0;
  }
  //Continous detection before notification
  if (colorCheckCntB > colorCheckCnt) {
    Serial.print(" Blue is detected. ");
    colorCheckCntB = colorCheckCnt;
  }
}
