#include "HeaderFiles/header.h"

int opcode(string instruction){
    string direct[]={};
    string inDirect[]={};
    string immediate[]={};
    string implicit[]={};
    stringstream temp(instruction);
    string opcode;
    getline(statement,temp,' ');
    int n = sizeof(direct)/sizeof()
    for(int i=0;i<n;i++)    if(direct[i]==opcode)   return 1;
    for(int i=0;i<n;i++)    if(inDirect[i]==opcode) return 2;
    for(int i=0;i<n;i++)    if(immediate[i]==opcode)    return 3;
    for(int i=0;i<n;i++)    if(implicit[i]==opcode) return 4;
}