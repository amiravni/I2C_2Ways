#include <Wire.h>

#define LED_PIN 13
byte x = 1;
byte d = 0;
void setup()
{
  Serial.begin(9600);
  Wire.begin(); // Start I2C Bus as Master
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

}
void loop()
{
  
  Wire.beginTransmission(3); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
    Wire.beginTransmission(4); // transmit to device #9
  Wire.write(6-x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  //  Serial.println(d);
  x++;
  if (x > 5) x=1;
  
  byte from3 = Wire.requestFrom(3,1);
  if (from3==1)
  {
    from3 = Wire.read();
  }
  byte from4 = Wire.requestFrom(4,1);
  if (from4==1)
  {
    from4 = Wire.read();
  }  
  Serial.print((int)from3);
  Serial.print(" , ");  
  Serial.println((int)from4);
  delay(5000);
  
}

/*
void receiveEvent(int howMany) {
  d = Wire.read();    // receive byte as an integer
}
*/
