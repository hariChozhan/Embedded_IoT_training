#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int gasSensor = 3;
int heater = 4;
int ac = 5;
int ventilator = 6;
float tempValue = 0;
int gasValue = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("********HVAC SYSTEM********");
  dht.begin();
  pinMode(gasSensor, INPUT);
  pinMode(heater, OUTPUT);
  pinMode(ac, OUTPUT);
  pinMode(ventilator, OUTPUT);
}
int readSensor() {
  tempValue = dht.readTemperature();
  gasValue = digitalRead(gasSensor);
  Serial.print("Temperature Value : ");
  Serial.println(tempValue);
  Serial.print("Gas Sensor Value : ");
  Serial.println(gasValue);
}
void loop() {
  readSensor();
  if (tempValue < 18) {
    Serial.begin("Heater : ON /n AC : OOF");
    digitalWrite(heater, HIGH); //HIGH or true or 1
    digitalWrite(ac, LOW);
  }
  else if (tempValue >= 18 && tempValue <= 22) {
    Serial.begin("Heater : OFF /n AC : OOF");
    digitalWrite(heater, 0);
    digitalWrite(heater, 0);
  }
  else if (tempValue > 22) {
    Serial.begin("Heater : OFF /n AC : ON");
    digitalWrite(ac, true);
    digitalWrite(heater, false);
  }
  if (gasValue == 1) {
    Serial.println("Ventilator : ON");
    digitalWrite(ventilator, HIGH);
  }
  else {
    Serial.println("Ventilator : ON");
    digitalWrite(ventilator, LOW);
  }
}
