#include <Arduino.h>
#include <i2c7seg.h>

i2c7seg SevenSeg;

void setup()
{
  SevenSeg.begin();
}

void loop()
{
  for (size_t i = 0; i < 9999; i++)
  {
    SevenSeg.LCDPrint(i);

    delay(50);
  }

}