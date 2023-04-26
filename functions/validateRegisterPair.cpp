#include "../HeaderFiles/header.h"
bool validateRegister(string regPair){
    if(regPair=="B"||regPair=="D"||regPair=="H"||regPair=="M")
        return true;
    else
        return false;
}