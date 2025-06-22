const int qtiPinL = 44;
const int qtiPinR = 45;
const int qtiFrontR = 42;
const int qtiFrontL = 43;
volatile int counter = 1;
volatile int countery = 1;
volatile bool prev_state = -1;
volatile bool state = -1;

volatile bool prev_statey = -1;
volatile bool statey = -1;

//motor driver LM298 control pin
int pin1R = 6;
int pin2R = 7;
int pin1L = 10;
int pin2L = 11;

volatile int x = 4;
volatile int y = 5;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(x>y){
    const int horizontal_dist = x - y;

    
  }else if(y>x){
    const int vertial_dist = y - x;

    
  }else{
    
  }

}

// Motor subrountine
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
