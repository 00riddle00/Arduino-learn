// Pins
const uint8_t btn_pin = 2;
const uint8_t led_pin = 5;

// Globals
uint8_t led_state = LOW;
uint8_t btn_prev = HIGH;

void setup() { 
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
}

void loop() {

  // Poll for button push
  uint8_t btn_state = digitalRead(btn_pin);
  if ((btn_state == LOW) && (btn_prev == HIGH)) {
    led_state = !led_state;
    digitalWrite(led_pin, led_state);
  }
  btn_prev = btn_state;
  
  // Pretend we're doing other stuff
  delay(500);
}

