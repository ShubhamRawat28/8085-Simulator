#include "HeaderFiles/header.h"

int registerNumber(string reg){
    if(reg == "B"||reg == "C")  return 0;
    if(reg == "D"||reg == "E")  return 1;
    if(reg == "H"||reg == "L")  return 2;
}