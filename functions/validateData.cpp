#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

bool checkHexa(char x){
    if((x>='0'&&x<='9')||(x>='A'&&x<='F'))  return true;
    else    return false;
}
bool validateData(string data){
    if(data.length()!=2)  return false;
    if(checkHexa(data[0])&&checkHexa(data[1]))  return true;
    return false;
}