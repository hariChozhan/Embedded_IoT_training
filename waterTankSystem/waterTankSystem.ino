int waterSensor1 = 2;
int waterSensor2 = 3;
int motor = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("********Water Tank System******");
  pinMode(waterSensor1, INPUT);
  pinMode(waterSensor2, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  int sensorValue1 = (digitalRead(waterSensor1));
  int sensorValue2 = (digitalRead(waterSensor2));
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  if (sensorValue1 == 1 && sensorValue2 == 0) {
    digitalWrite(motor, HIGH);
    Serial.println("Motor is turned ON");
  }
  else if (sensorValue1 == 0 && sensorValue2 == 0) {
    digitalWrite(motor, HIGH);
    Serial.println("Motor is turned ON");
  }
  else if (sensorValue1 == 0 && sensorValue2 == 1) {
    digitalWrite(motor, LOW);
    Serial.println("Motor is turned OFF");
  }
  delay(500);
}
