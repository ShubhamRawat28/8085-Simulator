#ifndef _ARITHEMATIC_H
#define _ARITHEMATIC_H
#include "header.h"

void ADD(string ,string &,string registers[],bool flag[],map<string,string>&);
void ADI(string , string &,bool flag[]);
void CMP(string, string registers[], string &, bool flag[], map<string, string> &);
void DAD(string , string registers[], bool flag[]);
void DCR(string ,string registers[],string ,bool flag[],map<string,string>&);
void DCX(string ,string registers[],bool flag[]);
void INR(string ,string registers[],string &,bool flag[],map<string,string>&);
void INX(string ,string registers[],bool flag[]);
void SBI(string ,string & , string registers[],bool flag[]);
void SUB(string ,string & ,string registers[],bool flag[],map<string,string>&);

#endif