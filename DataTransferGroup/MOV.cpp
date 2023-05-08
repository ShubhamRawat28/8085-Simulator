#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void MOV(string var1,string var2,string& accumulator,string registers[],map<string,string>&memory){
    if(!(var1.length()==1&&var2.length()==1)){
        cout<<"Enter a valid register";
        exit(0);
    }
    if(var1=="M"&&var2=="M")    return;
    if(var1=="A"&&var2=="A")    return;

    if(var1=="M"&&var2!="M"&&validateRegister(var2)){
        string mPoint = "";
        mPoint += registers[4];
        mPoint += registers[5];
        memory[mPoint] = registers[registerNumber(var2)];
    }
    else if(var1!="M"&&var2=="M"&&validateRegister(var1)){
        string mPoint = registers[4]+registers[5];
        registers[registerNumber(var1)] = memory[mPoint];
    }
    else if(var1!="A"&&var2=="A"&&validateRegister(var1)){
        registers[registerNumber(var1)] = accumulator;
    }
    else if(var1=="A"&&var2!="A"&&validateRegister(var2)){
        accumulator = registers[registerNumber(var2)];
    }
    else if(var1!="M"&&var2!="M"&&validateRegister(var2)&&validateRegister(var1)){
        registers[registerNumber(var1)] = registers[registerNumber(var2)];
    }
    else{
        cout<<"Invalid value of register, Please mention valid register"<<endl;
    }
}