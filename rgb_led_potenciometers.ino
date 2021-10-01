
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void loop()
{
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 255);
  
  auto pin3_value = analogRead(A0)/4; // since a.Read read gives 10 bit value
  analogWrite(3, pin3_value);  // a.Write writes 8 bit value
  
  auto pin5_value = analogRead(A1)/4;
  analogWrite(5, pin5_value);
  
  auto pin6_value = analogRead(A2)/4;
  analogWrite(6, pin6_value);
  
  delay(1);
}
