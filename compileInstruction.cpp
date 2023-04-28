#include "../8085-Simulator/HeaderFiles/header.h"
#include "../8085-Simulator/HeaderFiles/arithematic.h"
#include "../8085-Simulator/HeaderFiles/directAdd.h"
#include "../8085-Simulator/HeaderFiles/indirectAdd.h"
#include "../8085-Simulator/HeaderFiles/jump.h"
#include "../8085-Simulator/HeaderFiles/tools.h"

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