const int btn_pin = 2;
const int led_pin = 5;

void setup() { 
  DDRD = B00100000;
  PORTD = B00000100;
}

void loop() {
  int btn = (PIND & (1 << btn_pin)) >> btn_pin;

  if (btn == LOW) {
    PORTD |= (1 << led_pin);
  } else {
    PORTD &= ~(1 << led_pin);
  }
}
