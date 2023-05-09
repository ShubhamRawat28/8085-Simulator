#ifndef _LOGICAL_H
#define _LOGICAL_H
#include "header.h"

void ANA(string ,string& ,string registers[],map<string,string>&,bool flag[]);
void ANI(string ,string& ,map<string,string>&);;
void CMA(string& );
void ORA(string ,string& ,string registers[],map<string,string>&,bool flag[]);
void ORI(string ,string& ,map<string,string>&);
void XRA(string ,string& ,string registers[],map<string,string>&,bool flag[]);
void XRI(string ,string& ,map<string,string>&);

#endif