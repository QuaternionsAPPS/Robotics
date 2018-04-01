int trig = 8, echo = 7;
unsigned int duration, distance;

void setup() {
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  Serial.begin (9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds (10);
  digitalWrite(trig, LOW);
  delayMicroseconds (1);
  duration = pulseIn(echo, HIGH);
  if (duration > 37000){
    Serial.println("Error");
  }
  else {
    distance = duration * 0.034/2;
    Serial.println(distance);
  }
}
