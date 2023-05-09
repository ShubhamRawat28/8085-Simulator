#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/logical.h"

void ANA(string var,string& accumulator,string registers[],map<string,string>&memory,bool flag[]){
    if(var=="M"){
        string address = registers[4]+registers[5];
        accumulator = andHex(accumulator,memory[address]);
    }
    else if(validateRegister(var)){
        accumulator = andHex(accumulator,registers[registerNumber(var)]);
    }
    else{
        cout<<"Enter a valid register value"<<endl;
        exit(0);
    }
}