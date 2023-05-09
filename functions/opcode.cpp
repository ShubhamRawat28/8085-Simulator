#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

int opcode(string instruction){
    string oneByte[]={"ADD","SUB","MOV","HLT","LDAX"};
    //Instruction having one byte size
    string twoByte[]={"MVI","ANI","ORI","XRI","ADI","SBI"};
    //Instruction having two byte size
    string threeByte[]={"STA","LDA","JC","JNC","JZ","JNZ","LDAX","LHLD","LXI","SHLD","STAX"};
    //Instruction having three byte size
    stringstream temp(instruction);
    string opcode;
    getline(temp,opcode,' ');
    int n = sizeof(oneByte)/sizeof(oneByte[0]);
    for(int i=0;i<n;i++)    if(oneByte[i]==opcode)   return 1;
    n = sizeof(twoByte)/sizeof(twoByte[0]);
    for(int i=0;i<n;i++)    if(twoByte[i]==opcode) return 2;
    n = sizeof(threeByte)/sizeof(threeByte[0]);
    for(int i=0;i<n;i++)    if(threeByte[i]==opcode)    return 3;
    return 0;
}