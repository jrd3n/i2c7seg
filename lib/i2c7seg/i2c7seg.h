#ifndef i2c7seg_h
#define i2c7seg_h

#include <Arduino.h>

class i2c7seg
{
  public:
    i2c7seg();
    void begin();
    void LCDPrint(int displayValue);

  private:
    void LCDIntChar(int val, int position);
    byte Number[12] = {63, 6, 91, 79, 102, 109, 124, 7, 127, 103};
    int previousVal;
};

#endif