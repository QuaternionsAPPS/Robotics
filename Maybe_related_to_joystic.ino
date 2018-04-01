int sensorPinX = A0;
int sensorPinY = A1;
int sensorValueX = 0;
int sensorValueY = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValueX = analogRead (sensorPinX);
  sensorValueY = analogRead (sensorPinY);
  Serial.print(sensorValueX);
  Serial.print("\t");
  Serial.println(sensorValueY);
}
