#ifndef _TOOLS_H
#define _TOOLS_H
#include "header.h"

int hexaToDecimal(string);
void hexaToDecimal(string,int arr[]);
bool validateAddress(string);
vector<string> divideInsturuction(string);
bool validateRegisterPair(string);
int registerPairNumber(string);
bool validateRegister(string);
int registerNumber(string);
bool validateData(string);
string decimalToHexa(int);
void increaseAddress(string&);
void decreaseAddress(string&);
vector<string>divideInstruction(string);
string andHex(string,string);
string orHex(string,string);
string exorHex(string,string);
string hexaAdd(string,string,bool[],bool);
string hexaSub(string,string,bool[],bool);
int opcode(string);
void executeInstructions(string& pc,string& accumulator,string registers[], map<string, string>& memory, bool flags[]);
string complement(string);

#endif