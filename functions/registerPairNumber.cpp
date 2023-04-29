#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

int registerPairNumber(string x){
    if(x=="B")  return 0;
    else if(x=="D") return 2;
    else{
        cout<<"Enter a valid register register Pair"<<endl;
        exit(0);
    }
    return -1;
}