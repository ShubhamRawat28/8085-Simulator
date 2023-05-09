#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/branching.h"

void JNZ(string address,string& pc,bool flag[]){
    if(!validateAddress(address)){
        cout<<"Enter a valid address"<<endl;
        exit(0);
    }
    if(flag[1] == false) {
        pc = address;
    }
    else{
        increaseAddress(pc);
    }//Increase the current address and move to next command;
}