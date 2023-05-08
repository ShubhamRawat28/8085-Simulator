#ifndef _DATATRANSFER_H
#define _DATATRANSFER_H
#include "header.h"

void LDA(string,string&,map<string,string>&);
void LDAX(string,string&,string temp[],map<string,string>&);
void LHLD(string,string temp[],map<string,string>&);
void LXI(string,string,string temp[],map<string,string>&);
void MOV(string,string,string&,string temp[],map<string,string>&);
void MVI(string,string&,string,string temp[],map<string,string>&);
void SHLD(string,string&,string temp[],map<string,string>&);
void STA(string,string&,map<string,string>&);
void STAX(string,string&,string temp[],map<string,string>&);
void XCHG(string temp[],map<string,string>&);

#endif