#define R 2
#define B 6
#define G 7

int distancia_cm = 0;
int distancia_pol = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}


void setup(){
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  analogWrite(2, LOW);
  analogWrite(6, LOW);
  analogWrite(7, LOW);
  distancia_cm = 0.01723 * readUltrasonicDistance(3, 4);
  if (distancia_cm < 110) {
    Serial.println("Objeto proximo");
    analogWrite(R, (255));
  	analogWrite(G, (0));
	analogWrite(B, (0));
  }
  if (distancia_cm > 110 && distancia_cm < 200) {
    analogWrite(R, (255));
  	analogWrite(G, (255));
	analogWrite(B, (85));
  }
  if (distancia_cm > 200) {
    analogWrite(R, (0));
  	analogWrite(G, (255));
	analogWrite(B, (0));
  }
  Serial.print(distancia_cm);
  Serial.println("cm");
  delay(1000); // Wait for 1000 millisecond(s)
}
  
  
 
