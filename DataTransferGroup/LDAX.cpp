#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void LDAX(string var1,string& accumulator,string registers[],map<string,string>&memory){
    if(var1=="M"){
        string address = registers[4]+registers[5];
        accumulator = memory[address];
    }
    else if(validateRegisterPair(var1)){
        int pairIndex = registerPairNumber(var1);
        string address = registers[pairIndex] + registers[pairIndex+1];
        accumulator = memory[address];
    }
    else{
        cout<<"Enter a valid register pair"<<endl;
        exit(0);
    }
}