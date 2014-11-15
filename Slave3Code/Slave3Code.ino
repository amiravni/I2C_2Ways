#include <Wire.h>

#define LED_PIN 13

int x;

void setup() {
  Wire.begin(3);                // Start I2C Bus as a Slave (Device Number 9)
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, LOW);

  x = 0;
}

void loop() {
  
  for (int i=0; i<x;i++)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  }
  delay(1000);
}

void receiveEvent(int howMany) {
  x = Wire.read();    // receive byte as an integer
}

void requestEvent() {
  Wire.write(x);    // receive byte as an integer
}
