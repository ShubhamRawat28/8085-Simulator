#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

vector<string> divideInstruction(string instruction)
{
    vector<string> code;
    // divide into charr arr
    stringstream statement(instruction);
    string temp;
    getline(statement, temp, ' ');
    code.push_back(temp);
    while (getline(statement, temp, ','))
    {
        code.push_back(temp);
    }
    return code;
}