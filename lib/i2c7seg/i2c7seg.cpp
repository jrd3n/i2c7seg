#include <Arduino.h>
#include <i2c7seg.h>
#include "ht16k33.h"

HT16K33 HT;

i2c7seg::i2c7seg()
{
}

/****************************************************************/
void i2c7seg::begin()
{
    HT.begin(0x00);
}

void i2c7seg::LCDIntChar(int val, int position)
{
    byte Poss[4] = {64, 48, 16, 0};

    //byte character = B00111111;

    for (size_t i = 0; i < 8; i++)
    {
        if (bitRead(Number[val], i))
        {

            HT.setLedNow(i + Poss[position]);
        }
    }

}
/****************************************************************/

void i2c7seg::LCDPrint(int val)
{

    if (val != previousVal)
    {

        HT.clearAll();

        int num0 = val % 10;
        int num1 = (val / 10) % 10;
        int num2 = (val / 100) % 10;
        int num3 = (val / 1000) % 10;

        if (num0 == 0)
        {
            num0 = 11;
        }

        if (num1 == 0)
        {
            num1 = 11;
        }
        if (num2 == 0)
        {
            num2 = 11;
        }

        if (num3 == 0)
        {
            num3 = 11;
        }

        LCDIntChar(num0, 0);
        LCDIntChar(num1, 1);
        LCDIntChar(num2, 2);
        LCDIntChar(num3, 3);

        previousVal = val;
    }
}
