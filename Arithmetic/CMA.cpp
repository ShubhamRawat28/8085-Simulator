#include "../HeaderFiles/header.h"
#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void CMA(string registers[], string &accumulator, bool flags[])
{
    string cm = complement(accumulator);
    accumulator = cm;
    if (accumulator == "00")
    {
        flags[6] = true;
        flags[2] = true;
    }
    else
    {
        string temp = accumulator;
        int array[2];
        hexaToDecimal(temp, array);
        int value = array[1] * 16 + array[0];
        bitset<8> dataInBinary(value);
        int parity = dataInBinary.count();
        if (parity % 2 == 0 && parity != 0)
            flags[2] = true;
        else
            flags[2] = false;
    }
}