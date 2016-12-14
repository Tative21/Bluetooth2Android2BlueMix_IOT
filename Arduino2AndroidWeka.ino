#include <SoftwareSerial.h>
#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#define DEBUG
#ifdef DEBUG
#include "DebugUtils.h"
#endif

#include "CommunicationUtils.h"
#include "FreeSixIMU.h"
#include <Wire.h>

const int RX_PIN = 0;
const int TX_PIN = 1;
SoftwareSerial serial(RX_PIN, TX_PIN);
char commandChar;
int q[6]; //hold raw values for acc & gyro
FreeSixIMU my3IMU = FreeSixIMU(); // Set the FreeIMU object

void setup ()
{
serial.begin (9600);
Wire.begin();
randomSeed(analogRead(0));
delay(5);
my3IMU.init();
delay(5);
}
void loop ()
{
//my3IMU.getRawValues(q);
//Serial.print("h"); // send a header character
//Serial.print(",");
//Serial.print(q[0]);
//Serial.print(",");
//Serial.print(q[1]);
//Serial.print(",");  
//Serial.print(q[2]);
//Serial.print(",");
//Serial.print(q[3]);
//Serial.print(",");
//Serial.print(q[4]);
//Serial.print(",");  
//Serial.print(q[5]); 
//Serial.print(",\n");  


if(serial.available())
{
commandChar = serial.read();
switch(commandChar)
{
case '*':
while(1){
my3IMU.getRawValues(q);
serial.print("#");
serial.print(","); 
for(int i = 0; i<=5;i++){
  
  serial.print(q[i]);
  serial.print(","); 
}

serial.print("~");
delay(60);
}
}
}
}
