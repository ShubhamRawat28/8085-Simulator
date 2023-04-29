#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void increaseAddress(string& currAddress){
    int current = hexaToDecimal(currAddress);
    current++;
    currAddress = decimalToHexa(current);
}