void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("LDR1 ");
  Serial.print(analogRead(A0));
  Serial.print(" LDR2 ");
  Serial.print(analogRead(A1));
  Serial.print(" LDR3 ");
  Serial.print(analogRead(A2));
  Serial.print(" LDR4 ");
  Serial.println(analogRead(A3));
}
