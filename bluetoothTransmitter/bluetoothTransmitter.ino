#include <SoftwareSerial.h>
SoftwareSerial btt(6, 7); // (Rx,Tx)

void setup() {
  Serial.begin(9600);
  btt.begin(115200);
  Serial.println("********BLUETOOTH COMMUNICATION PROTOCOL - TRANSMITTER**********");
}

void loop() {
  Serial.println("A");
  btt.write("A");
  delay(500);
}
