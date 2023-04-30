#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

string exorHex(string a,string b){
    for(int i=0;i<a.length();i++){
        if(a[i]=='1'&&b[i]=='1')    a[i] = '0';
        else if(a[i]=='0'&&b[i]=='1')    a[i] = '1';
        else if(a[i]=='1'&&b[i]=='0')    a[i] = '1';
        else if(a[i]=='0'&&b[i]=='0')    a[i] = '0';
    }
    return a;
}