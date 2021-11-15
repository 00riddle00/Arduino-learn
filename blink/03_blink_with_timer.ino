// Pins
const int led_pin = PB5;

// Counter and compare values
const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

void setup() {
   
  // Set LED pin to be output
  DDRB |= (1 << led_pin);  // DDRD = xx1xxxxx
  
  // Reset Timer1 Control Register A
  // to its default value
  //
  // We don't need this register for what we're
  // doing, but Arduino has the habit of setting
  // the bits in this register by default for the 
  // analog write functions
  //
  TCCR1A = 0; // TCCR1A = 00000000
  
  // Set to select the prescaler of 256
  // CS12 = 2
  // CS11 = 1
  // CS10 = 0
  //
  TCCR1B |= (1 << CS12);  // TCCR1B = xxxxx1xx
  TCCR1B &= ~(1 << CS11); // TCCR1B = xxxxx10x
  TCCR1B &= ~(1 << CS10); // TCCR1B = xxxxx100
  
  // Reset Timer1 (ie. load the actual timer with 0)
  TCNT1 = t1_load;
  // Store our "match value" into the Output Compare
  // Register 1A.
  OCR1A = t1_comp;
  
  // Enable Timer1 output compare interrupt
  // OCIE1A - Timer1 Output Compare A Match Interrupt Enable bit
  // OCIE1A = 1
  TIMSK1 = (1 << OCIE1A); // TIMSK1 = xxxxxx1x;
  
  // Enable global interrupts
  sei();
}

void loop() {
  
  // Pretend we're doing other stuff
  delay(500);
}

// Create interrupt service routine for Timer1 Compare A Match vector.
ISR(TIMER1_COMPA_vect) {
  // Reset Timer1 to 0;
  TCNT1 = t1_load;
  PORTB ^= (1 << led_pin); // flip between 0V and 5V on led_pin
}
