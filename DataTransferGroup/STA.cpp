#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void STA(string address,string accumulator,map<string,string>&memory){
    if(!validateAddress(address)){
        cout<<"Enter a valid address"<<endl;
        exit(0);
    }
    else{
        memory[address] = accumulator;
    }
}