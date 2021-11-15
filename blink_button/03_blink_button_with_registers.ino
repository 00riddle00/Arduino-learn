const int btn_pin = 2;
const int led_pin = 5;

void setup() { 
  DDRD = B00100000; // use pin 5 as output for LED
  PORTD = B00000100; // enable internal pull-up resistor on pin 2
}

void loop() {
  // check if button is pressed (ie. if PIND 2nd bit is on)
  int btn = (PIND & (1 << btn_pin)) >> btn_pin;

  if (btn == LOW) {
    PORTD |= (1 << led_pin); // output 5V on pin5
                             // PORTD = 00100100
  } else {
    PORTD &= ~(1 << led_pin); // output 0V on pin5
                              // PORTD = 00000100
  }
}
