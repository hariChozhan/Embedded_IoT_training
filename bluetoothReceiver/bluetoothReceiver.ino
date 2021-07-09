#include <SoftwareSerial.h>
SoftwareSerial btr(4, 5);        // (Rx,Tx)
char c = 'a';
void setup() {
  Serial.begin(9600); // Initialize Hardware Serial
  btr.begin(115200); // Initialize Software Serial
  Serial.println("********BLUETOOTH COMMUNICATION PROTOCOL - RECEIVER**********");
}

void loop() {
  while (btr.available() > 0) {    // Check if data is available or not
    c = btr.read();                // Reads the data through BT and stores in 'c'
    Serial.println(c);
  }
}
