#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/datatransfer.h"

void STAX(string var1,string& accumulator,string registers[],map<string,string>&memory){
    if(var1=="M"){
        string address = registers[4]+registers[5];
        memory[address] = accumulator;
    }
    else if(validateRegister(var1)){
        int pairIndex = registerNumber(var1);
        string address = registers[pairIndex] + registers[pairIndex+1];
        memory[address] = accumulator;
    }
    else{
        cout<<"Enter a valid register pair"<<endl;
        exit(0);
    }
}