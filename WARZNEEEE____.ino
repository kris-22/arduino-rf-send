#include<SoftwareSerial.h>
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
SoftwareSerial SUART(2, 3); //SRX = DPin-2; STX = DPin-3

String y;
void setup()
{
  mySwitch.setPulseLength(161);
  mySwitch.enableTransmit(10);
  Serial.begin(9600);
  SUART.begin(9600);
  Serial.println("ready");
}

void loop()
{
  if (SUART.available())
  {
    char x = SUART.read();
    if (x == '\r') {
      if (y.startsWith("rad=")) {
        int index = y.indexOf("=");
        index ++;
        y = y.substring(index);
        int z =y.toInt();
//        Serial.println("string: "+y);
        mySwitch.send(z, 24);
//        Serial.println("string clear: "+y); 
        y=""; 
      }
    }else if (x != '\n') {
       y = y + String(x);
    }
   }
}


