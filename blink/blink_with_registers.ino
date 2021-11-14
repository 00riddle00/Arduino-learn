const int led_pin = PB5;

void setup() { 
  // Set LED pin to be output
  DDRB |= (1 << (led_pin));
}

void loop() {
  // output either 5V or 0V on led_pin;
  PORTB ^= (1 << led_pin);

  delay(500);
}
