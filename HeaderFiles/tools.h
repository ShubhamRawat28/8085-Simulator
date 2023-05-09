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
string hexaAdd(string,string,bool temp[],bool);
string hexaSub(string,string,bool temp[],bool);
int opcode(string);
void executionDebugger(string& pc,string& accumulator,map<string,string>&memory,bool flags[],string registers[]);
void executeInstructions(string&,string&,string registers[], map<string, string>&, bool flags[]);
void execute(string&,string&,string registers[], map<string, string>&, bool flags[]);
void display(string& accumulator,string registers[],bool flags[]);


#endif