#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void MOV(string var1,string var2,string register[6],pair<string,string>&regisPair[3],map<string,string>&memory){
    if(var1.length()!=1||var2.length()!=1)  return false;
    if(var1=="M"&&var2=="M")    return;
    if(var1=="M"&&var2!="M"&&validateRegister(var2)){
        string mPoint = registerPair[2].first+registerPair[2].second;
        memory[mPoint] = register[registerNumber(var2)];
    }
    else if(var1!="M"&&var2=="M"&&validateRegister(var1)){
        string mPoint = registerPair[2].first+registerPair[2].second;
        register[registerNumber(var1)] = memory[mPoint];
    }
    else if(var1!="M"&&var2!="M"&&validateRegister(var2)&&validateRegister(var1)){
        register[registerNumber(var1)] = register[registerNumber(var2)];
    }
    else{
        cout<<"Invalid value of register, Please mention valid register"<<endl;
    }
}