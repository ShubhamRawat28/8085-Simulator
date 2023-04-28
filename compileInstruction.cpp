#include "./HeaderFiles/header.h"
#include "./HeaderFiles/arithematic.h"
#include "./HeaderFiles/directAdd.h"
#include "./HeaderFiles/indirectAdd.h"
#include "./HeaderFiles/jump.h"
#include "./HeaderFiles/tools.h"

string compile(string command,pair<string,string>[]regis,bool flag[],map<string,string>&memory,string pc){
    vector<string>byteIns = divideInstruction(command);
    if(byteIns[0]=="ADD"){
        cout<<"This is add instruction";

        return nextAddress(pc,commandSize);
    }
    else if(byteIns[0]=="SUB")
        cout<<"This is sub instruction";
    //.....for all the commands;

    return ""
}