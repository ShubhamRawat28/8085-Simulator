#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void XCHG(string registers[],map<string,string>&memory){
    string data = registers[2];
    registers[2] = registers[4];
    registers[4] = data;
    //exchange the data of D with H
    data = registers[2];
    registers[2] = registers[4];
    registers[4] = data;
    //exchange the data of E with L
}