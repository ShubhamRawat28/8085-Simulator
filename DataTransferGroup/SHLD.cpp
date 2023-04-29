#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void SHLD(string address,string& accumulator,string registers[],map<string,string>&memory){
    if(!validateAddress(address)){
        cout<<"Enter a valid address"<<endl;
        exit(0);
    }
    else{
        memory[address] = registers[4];
        increaseAddress(address);
        memory[address] = registers[5];
    }
}