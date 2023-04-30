#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void XRA(string var,string& accumulator,string registers[],map<string,string>&memory,bool flag[]){
    if(var=="M"){
        string address = registers[4]+registers[5];
        accumulator = exorHex(accumulator,memory[address]);
    }
    else if(validateRegister(var)){
        accumulator = exorHex(accumulator,registers[registerNumber(var)]);
    }
    else{
        cout<<"Enter a valid register value"<<endl;
        exit(0);
    }
}