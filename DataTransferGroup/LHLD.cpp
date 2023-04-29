#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void LHLD(string address,string registers[],map<string,string>&memory){
    if(!validateAddress(address)){
        cout<<"Enter a valid address"<<endl;
        exit(0);
    }
    else{
        registers[4] = memory[address];
        increaseAddress(address);
        registers[5] = memory[address];
    }
}