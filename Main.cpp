#include "./HeaderFiles/header.h"
#include "./HeaderFiles/tools.h"

class Emulator_8085
{
    map<string, string> memory;
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
            
        }
        input_file.close();
    }
    void display(){
        cout<<"All the registers currently"<<endl;
        cout << setw(2) << "A:" << setw(3) << accumulator <<"   ";
        cout << setw(2) << "B:" << setw(3) << registers[0] << "   ";
        cout << setw(2) << "C:" << setw(3) << registers[1] << "   ";
        cout << setw(2) << "D:" << setw(3) << registers[2] << "   ";
        cout << setw(2) << "E:" << setw(3) << registers[3] << "   ";
        cout << setw(2) << "H:" << setw(3) << registers[4] << "   ";
        cout << setw(2) << "L:" << setw(3) << registers[5] << "   ";
    }
    void displayMemory(string address){
        char choice = 'x';
        cout<<"Enter 1 to exit this mode";
        while(choice!='1'){
            cout<<address<<" : "<< memory[address];
            string updation;
            cin>>updation;
            if(validateData(updation))
                if(updation != "1") memory[address] = updation;
            else    cout<<"Invalid data value"<<endl;
            choice = updation[0];
        }
    }
};

int main()
{
    Emulator_8085 machine;
    cout<<"Enter the mode you want to open"<<endl<<"A - to Enter the code"<<endl<<"M - To access the memory"<<endl<<"G - to run the code";
    string mode;
    cin>>mode;
    if(mode == "M"){
        cout<<"Enter the memory address you want to check"<<endl;
        string address;
        cin>>address;
        machine.displayMemory(address);
    }
    else if(mode == "A"){
        machine.input();
        machine.readFile();
        cout<<"Successfully read the code written in the test file no errors"<<endl;
    }
    else if(mode == "G"){


    }
    else{
        cout<<"Enter a valid mode Restart the machine"<<endl;
    }

    return 0;
}