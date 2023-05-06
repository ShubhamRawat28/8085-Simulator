#include "../HeaderFiles/header.h"

bool validateRegisterPair(string reg)
{
    if(reg == "B" || reg == "D" || reg == "H" || reg == "SP"|| reg == "PSW" || reg == "M")
        return true;
    else
        return false;
}