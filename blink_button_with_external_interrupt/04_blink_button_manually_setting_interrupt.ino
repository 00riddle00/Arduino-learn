// Pins
const uint8_t btn_pin = 2;
const uint8_t led_pin = 5;

void setup() { 
  
  // set button pin to be input (btn_pin bit=0) with pullup
  DDRD &= ~(1 << btn_pin);  // DDRD = xxxxx0xx
  PORTD |= (1 << btn_pin);  // PORTD = xxxxx1xx
  
  // set LED pin to be output
  DDRD |= (1 << led_pin); // DDRD = xx1xx0xx
   
  // Falling edge of INT0  generates interrupt
  EICRA |= (1 << ISC01);  // EICRA = xxxxxx1x
  EICRA &= ~(1 << ISC00); // EICRA = xxxxxx10
  
  // Enable interrupts for INT0
  EIMSK |= (1 << INT0); // EIMSK = xxxxxxx1
  
  // Enable global interrupts
  sei(); // SREG = 1xxxxxxx
}

void loop() {
  
  // Pretend we're doing other stuff
  delay(500);
}

// This tells the compiler that this is the service routine
// that should be run whenever an INT0 interrupt occurs.
//
// INT0_vect is the identifier meaning "External Interrupt Request 0"
// This vector number is 2
ISR(INT0_vect) {
  PORTD ^= (1 << led_pin);
}

