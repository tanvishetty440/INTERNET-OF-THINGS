// C++ code
//
void setup()
{
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int temp=digitalRead(8);
  Serial.println("Intensity");
  Serial.println(temp);
  delay(300);
  if(temp==HIGH)
  digitalWrite(5, HIGH);
  else
  digitalWrite(5, LOW);
}
