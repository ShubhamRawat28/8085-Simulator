#include "./HeaderFiles/header.h"
#include "./HeaderFiles/tools.h"

class Emulator_8085
{
    map<string, string> Memory;
    bool flags[5]; 
    //sign - zero - auxiliary carry - parity - carry
    string registers[6];
    string accumulator;                // Main register which will be used for every arithematic operation
    string pc;
    string start;
    vector<string> codeAddress;

public:
    Emulator_8085()
    {
        flags[5] = {false}; // Set all the flags to zero
        for (int i = 0; i < 3; i++)
        {
            registers[i] = {"", ""};
        }
        registers[6] = {""};
        accumulator = "";
        pc = "";
        // Set all the register to null in start
    }

    void input()
    {
        cout << "Enter a VALID START ADDRESS" << endl;
        cin >> start;
        if (!validateAddress(start))
        {
            cout << "The address entered is invalid or reserved by the processor" << endl
                 << "Please Enter a valid address" << endl
                 << "Program logging off" << endl;
            exit(0);
        }
        else
            codeAddress.push_back(start);
    }
    vector<string> readFile()
    {
        string filename("input.txt");
        vector<string> instructions;
        string line;

        ifstream input_file(filename);
        if (!input_file.is_open())
        {
            cerr << "Could not open the file - '"
                 << filename << "'" << endl;
            exit(0);
        }
        while (getline(input_file, line))
        {
            instructions.push_back(line);
        }
        input_file.close();
        return instructions;
    }
};

int main()
{
    Emulator_8085 machine;
    machine.input();
    vector<string>instructions = machine.readFile();
    return 0;
}