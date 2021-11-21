// Assign LED pin i.e: D1 on NodeMCU
int ledPin = D1;

void setup() {

  // Set LED as output
  pinMode(ledPin, OUTPUT);

  // Serial monitor setup
  Serial.begin(115200);
}

void loop() {

  Serial.print("Hello");
  
  digitalWrite(ledPin, HIGH);
  delay(1000);


  Serial.print(" world!");
  digitalWrite(ledPin, LOW);

  delay(1000);
}
