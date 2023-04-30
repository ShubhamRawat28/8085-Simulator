#ifndef _TOOLS_H
#define _TOOLS_H

int hexaToDecimal(string);
bool validateAddress(string);
vector<string> divideInsturuction(string);
bool validateRegisterPair(string);
int registerPairNumber(string);
bool validateRegister(string);
int registerNumber(string);
bool validateData(string);
string decimalToHexa(int);
void increaseAddress(string&);
vector<string>divideInstruction(string);
string andHex(string,string);
string orHex(string,string);
string exorHex(string,string);

#endif