#define TRIG 9 
#define ECHO 10

long duration; 
float distance; 
float tankDepth = 15.0; 
float waterLevel; 

void setup() {
  Serial.begin(9600); 
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT); 
}

void loop() {
 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  
  duration = pulseIn(ECHO, HIGH);
  
  distance = duration * 0.034 / 2;

 
  waterLevel = tankDepth - distance;

  if (waterLevel < 0) waterLevel = 0; 
  if (waterLevel > tankDepth) waterLevel = tankDepth; 

 
  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.print(" cm / Depth: ");
  Serial.print(tankDepth);
  Serial.println(" cm");

  delay(1000); 
}
