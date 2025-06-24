// set timer1 interrupt at 1Hz

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  cli();    // disable global interrupts

  // reset Timer 1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  /////////////////

  
  OCR1A = 15624;    // set the compare match register

  TCCR1B |= (1 << WGM12);  // turn on CTC mode
  
  TCCR1B |= (1 << CS12) | (1 << CS10);  // set prescaler
  
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  
  sei();  // enable interrupts
}


// function to be called when Timer 1 interrupts
ISR(TIMER1_COMPA_vect) {
  Serial.println("here!");
}


void loop() {
  // put your main code here, to run repeatedly:
}
