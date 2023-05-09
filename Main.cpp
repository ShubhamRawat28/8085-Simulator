#include "./HeaderFiles/header.h"
#include "./HeaderFiles/datatransfer.h"
#include "./HeaderFiles/tools.h"
#include "./HeaderFiles/logical.h"
#include "./HeaderFiles/arithematic.h"
#include "./HeaderFiles/branching.h"

class Emulator_8085
{
public:
    map<string, string> memory;
    bool flags[8];
    // sign - zero - auxiliary carry - parity - carry
    string registers[6];
    string accumulator; // Main register which will be used for every arithematic operation
    string pc;
    string start;
    Emulator_8085()
    {
        for (int i = 0; i < 5; i++)
            flags[i] = false; // Set all the flags to zero
        for (int i = 0; i < 6; i++)
            registers[i] = "00";
        accumulator = "00";
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
        pc = start;
    }
    void readFile()
    {
        string filename("input.txt");
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
            vector<string> curr = divideInstruction(line);
            string command = curr[0];
            int commandSize = opcode(command);
            for(auto it:curr)   cout<<it<<" ";
            cout<<endl;
            if (commandSize == 1)
            {
                memory[start] = line;
            }
            else if (commandSize == 2)
            {
                memory[start] = command;
                string var = curr[1];
                if (validateData(var))
                {
                    increaseAddress(start);
                    memory[start] = var;
                }
                else
                {
                    string data = curr[2];
                    memory[start] += " " + curr[1];
                    increaseAddress(start);
                    memory[start] = data;
                }
            }
            else
            {
                memory[start] = command;
                string var = curr[1];
                if (validateAddress(var))
                {
                    increaseAddress(start);
                    string half = "";
                    half += var[0];
                    half += var[1];
                    memory[start] = half;
                    half = "";
                    half += var[2];
                    half += var[3];
                    increaseAddress(start);
                    memory[start] = half;
                }
                else
                {
                    memory[start] += " " + curr[1];
                    increaseAddress(start);
                    string half = "";
                    half += var[0];
                    half += var[1];
                    memory[start] = half;
                    half = "";
                    half += var[2];
                    half += var[3];
                    increaseAddress(start);
                    memory[start] = half;
                }
            }
            increaseAddress(start);
        }
        cout<<"running..."<<endl;
        input_file.close();
    }
    void printCode(){
        string filename("input.txt");
        string line;
        ifstream input_file(filename);
        if (!input_file.is_open())
        {
            cerr << "Could not open the file - '"
                 << filename << "'" << endl;
            exit(0);
        }
        string temp = pc;
        while (getline(input_file, line))
        {
            vector<string> curr = divideInstruction(line);
            string command = curr[0];
            int commandSize = opcode(command);
            cout<<temp<< " : " << line <<endl;
            if (commandSize == 1)
            {
                increaseAddress(temp);
            }
            else if (commandSize == 2)
            {
                increaseAddress(temp);
                increaseAddress(temp);
            }
            else
            {
                increaseAddress(temp);
                increaseAddress(temp);
                increaseAddress(temp);
            }
        }
        input_file.close();
    }
    void displayMemory(string address)
    {
        cout << "Enter -1 to exit this mode" << endl;
        while (1)
        {
            if (memory[address].length() == 0)
                memory[address] = "00";
            cout << address << " : " << memory[address] << " : ";
            string updation;
            cin >> updation;
            if (updation == "-1")
                break;
            if (validateData(updation))
            {
                if (updation != "-1")
                    memory[address] = updation;
            }
            else
            {
                cout << "Invalid data value" << endl;
                exit(0);
            }
            increaseAddress(address);
        }
    }
};

int main()
{
    Emulator_8085 machine;
    while (1)
    {
        cout << "Enter the mode you want to open" <<endl
             << "------------------------------------------------------------------------------------------------------------------------------------------"<<endl
             << " A - To Enter the code" << " M - To access the memory" << " G - To run the code" << " D - To enter debugger mode"<< " X - To exit the program" <<endl
             << "------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        string mode;
        cin >> mode;
        if (mode == "X")
            break;
        if (mode == "M")
        {
            cout << "Enter the memory address you want to check" << endl;
            string address;
            cin >> address;
            machine.displayMemory(address);
        }
        else if(mode == "D"){
            executionDebugger(machine.pc,machine.accumulator,machine.memory,machine.flags,machine.registers);
        }
        else if (mode == "A")
        {
            machine.input();
            machine.readFile();
            cout << "Successfully read the code from the file"<< endl <<"No errors" << endl;
        }
        else if (mode == "G")
        {
            executeInstructions(machine.pc, machine.accumulator, machine.registers, machine.memory, machine.flags);
            display(machine.accumulator,machine.registers,machine.flags);
        }
        else
        {
            cout << "Enter a valid mode Restart the machine" << endl;
        }
    }
    return 0;
}