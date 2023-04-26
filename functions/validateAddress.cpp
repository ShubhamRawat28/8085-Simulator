#include "../HeaderFiles/header.h";

bool validateAddress(string address){
    if(address.length()!=4) return false;
    //Valid address 0000 H to FFFF H.
    for(int i=0;i<address.length();i++){
        if((address[i]>='0'&&address[i]<='9')||(address[i]>='A'&&address[i]<='F'))
            continue;
        else
            return false;
    }
    return true;
}