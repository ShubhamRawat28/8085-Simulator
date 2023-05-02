#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/datatransfer.h"

void LDA(string address,string& accumulator,map<string,string>&memory){
    if(!validateAddress(address)){
        cout<<"Please enter a valid address"<<endl;
        exit(0);
    }
    else{
        accumulator = memory[address];
    }
}