const int led_pin = PB5;

void setup() { 
  // Set LED pin to be output
  DDRB |= (1 << (led_pin)); // DDRB = xx1xxxxx;
}

void loop() {
  // output either 5V or 0V on led_pin;
  PORTB ^= (1 << led_pin); // PORTB = xx{0,1}xxxxx;

  delay(500);
}
