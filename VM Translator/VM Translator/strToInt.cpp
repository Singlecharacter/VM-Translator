#include "strToInt.h"

int strToInt(std::string str)
{
    int digit, num = 0;
    for(int i = 0;i<str.length();i++)
    {
        digit = str[i] - 48;
        num = num * 10;
        num += digit;
    }

    return num;
}
