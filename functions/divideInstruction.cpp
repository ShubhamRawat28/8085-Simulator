#include "../HeaderFiles/header.h"
vector<string> getAddress(string(instruction))
{
    vector<string> code;
    // divide into charr arr
    stringstream statement(instruction);
    string temp;
    getline(statement, temp, ' ');
    arr.push_back(temp);
    while (getline(statement, temp, ','))
    {
        code.push_back(temp);
    }
    return code;
}