// Pins
const uint8_t btn_pin = 2;
const uint8_t led_pin = 5;

void setup() { 
  
  // set button pin to be input (btn_pin bit=0) with pullup
  DDRD &= ~(1 << btn_pin);  // DDRD = xxxxx0xx
  PORTD |= (1 << btn_pin);  // PORTD = xxxxx1xx
  
  // set LED pin to be output
  DDRD |= (1 << led_pin); // DDRD = xx1xx0xx
  
  attachInterrupt(digitalPinToInterrupt(btn_pin), toggle, FALLING);
}
  
void loop() {
  
  // Pretend we're doing other stuff
  delay(500);
}

void toggle() {
  PORTD ^= (1 << led_pin); // flip between 0V and 5V on led_pin
                           // PORTD = xx{0,1}xx1xx
}

