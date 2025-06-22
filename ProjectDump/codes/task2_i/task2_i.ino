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


  while(counter < x){
    x_move();
  }

  turnCarOnsiteL();
  delay(200);

  
  while(countery < y){
    y_move();
  }
  stopCar();
  delay(5000);
}

void x_move(){

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


  if(black_or_whiteL==LOW and black_or_whiteR==LOW){
    state = 1;
  }else{
    state = 0;
  }
  
  if(state==1 and prev_state==0){
    counter += 1;
  }

  if(prev_state == state){
    
    forwardCar();
  }
  
  
}


void y_move(){

  

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

  if(statey != -1){
    prev_statey = statey;
  }
  

  byte black_or_whiteL = digitalRead(qtiPinL);
  byte black_or_whiteR = digitalRead(qtiPinR);

  byte black_or_whiteLF = digitalRead(qtiFrontL);
  byte black_or_whiteRF = digitalRead(qtiFrontR);


  if(black_or_whiteL==LOW and black_or_whiteR==LOW){
    statey = 1;
  }else{
    //counter += 1;
    statey = 0;
  }
  
  if(statey==1 and prev_statey==0){
    countery += 1;
    //state = 0;
  }

  if(prev_statey == statey){
    
    forwardCar();
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
