#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/logical.h"

void CMA(string& accumulator){
    for(int i=0;i<accumulator.length();i++){
        if(accumulator[i]=='0') accumulator[i] = '1';
        else    accumulator[i] = '0';
    }
}