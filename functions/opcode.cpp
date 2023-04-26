#include "../HeaderFiles/header.h"

int opcode(string instruction){
    string direct[]={"xyzr","xyz","zysei"};
    string inDirect[]={};
    string immediate[]={};
    string implicit[]={};
    stringstream temp(instruction);
    string opcode;
    getline(temp,opcode,' ');
    int n = sizeof(direct)/sizeof(direct[0]);
    for(int i=0;i<n;i++)    if(direct[i]==opcode)   return 1;
    n = sizeof(inDirect)/sizeof(inDirect[0]);
    for(int i=0;i<n;i++)    if(inDirect[i]==opcode) return 2;
    n = sizeof(immediate)/sizeof(immediate[0]);
    for(int i=0;i<n;i++)    if(immediate[i]==opcode)    return 3;
    n = sizeof(implicit)/sizeof(implicit[0]);
    for(int i=0;i<n;i++)    if(implicit[i]==opcode) return 4;
    return 0;
}