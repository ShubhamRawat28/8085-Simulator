#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/datatransfer.h"

void LXI(string var1,string data,string registers[],map<string,string>&memory){
    if(var1=="M"){
        string address = registers[4]+registers[5];
        memory[address] = data;
    }
    else if(validateRegister(var1)){
        int pairIndex = registerNumber(var1);
        string address = registers[pairIndex] + registers[pairIndex+1];
        memory[address] = data;
    }
    else{
        cout<<"Enter a valid register pair"<<endl;
        exit(0);
    }
}