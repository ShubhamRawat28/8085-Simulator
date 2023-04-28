#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void MVI(string var1,string& accumulator,string data,string register[],map<string,string>&memory){
    if(!validateData(data)){
        cout<<"Enter valid data amount"<<endl;
        exit(0);
    }
    if(var1=="M"){
        string address = register[4]+register[5];
        memory[address] = data;
    }
    else if(var1=="A"){
        accumulator = data;
    }
    else if(validateRegister(var1)){
        register[registerNumber(var1)] = data;
    }
    else{
        cout<<"Enter valid register value"<<endl;
        exit(0);
    }
}