// Pins
const uint8_t btn_pin = 2;
const uint8_t led_pin = 5;

// Globals
uint8_t led_state = LOW;

void setup() { 
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(btn_pin), toggle, FALLING);
}

void loop() {
  
  // Pretend we're doing other stuff
  delay(500);
}

void toggle() {
  led_state = !led_state;
  digitalWrite(led_pin, led_state);
}
