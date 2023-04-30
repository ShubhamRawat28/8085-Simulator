#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

string orHex(string a,string b){
    for(int i=0;i<a.length();i++){
        if(a[i]=='0'&&b[i]=='0')    a[i] = '0';
        else    a[i] = '1';
    }
    return a;
}