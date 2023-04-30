#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void ANI(string data,string& accumulator,map<string,string>&memory){
    if(validateData(data)){
        accumulator = andHex(accumulator,data);
    }
    else{
        cout<<"Enter valid data"<<endl;
        exit(0);
    }
}