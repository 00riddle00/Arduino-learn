// Blinking LED
const int LED = 13; // LED connected to digital pin 13

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED, OUTPUT); // sets the digital pin as output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
