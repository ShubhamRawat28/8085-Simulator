#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

string hexaToBinary(char x){
    int num;
    if(x>='0'&&x<='9')  num = x-'0';
    else    num = x-'A'+10;
    string binary = "";
    int cnt = 0;
    while(num){
        binary += to_string(num%2);
        num=num/2;
        cnt++;
    }
    while(cnt<4){
        binary += to_string(0);
        cnt++;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}