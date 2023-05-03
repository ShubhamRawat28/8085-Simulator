#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void XRI(string data,string& accumulator,map<string,string>&memory){
    if(validateData(data)){
        accumulator = exorHex(accumulator,data);
    }
    else{
        cout<<"Enter valid data"<<endl;
        exit(0);
    }
}