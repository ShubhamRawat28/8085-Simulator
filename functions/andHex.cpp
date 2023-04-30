#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

string andHex(string a,string b){
    for(int i=0;i<a.length();i++){
        if(a[i]=='1'&&b[i]=='1')    a[i] = '1';
        else    a[i] = '0';
    }
    return a;
}