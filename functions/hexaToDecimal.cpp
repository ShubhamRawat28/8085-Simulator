#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"


void hexaToDecimal(string pc,int arr[])
{
    int n = pc.length();
    for(int i=0;i<n;i++)
    {
        if(pc[i]>='0' && pc[i]<='9'){
            arr[i]=pc[i]-'0';
        }
        else{
            arr[i]=(pc[i]-'A')+10;
        }
    }
}


//overloading of the function 
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
<<<<<<< HEAD


=======
>>>>>>> d7f68f68f11b09c541d7cf6ea283091922d58d74
