#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

int hexaToDecimal(string number){
    reverse(number.begin(),number.end());
    int numberInt = 0;
    int mul = 1;
    for(int i=0;i<number.length();i++){
        if(number[i]>='A'&&number[i]<='F'){
            numberInt += ((number[i]-'A')+10)*mul;
        }
        else{
            numberInt += (number[i]-'0')*mul;
        }
        mul*=16;
    }
    return numberInt;
}
