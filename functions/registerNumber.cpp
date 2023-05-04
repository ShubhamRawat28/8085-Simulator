#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

int registerNumber(string reg){
    if(reg == "B")  return 0;
    if(reg == "C")  return 1;
    if(reg == "D")  return 2;
    if(reg == "E")  return 3;
    if(reg == "H")  return 4;
    if(reg == "L")  return 5;

    return -1;
}