
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen))
    {
	    int i;
      String s="";
      for(int x=0;x<buflen;x++)
     { s=s+(char)buf[i];}
     //or driver.printBuffer("Got:", buf, buflen);
     Serial.println(s);
    }
}
