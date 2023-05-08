#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void decreaseAddress(string& currAddress){
    int current = hexaToDecimal(currAddress);
    current--;
    currAddress = decimalToHexa(current);
}