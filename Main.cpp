#include "../8085-Simulator/HeaderFiles/header.h"
#include "../8085-Simulator/HeaderFiles/tools.h"
class Emulator_8085{
    map<string, string> Memory;
    bool flags[8];
    pair<string,string>registers[3];//Taking as string pair as 4 register pairs are there
    string accumulator;//Main register which will be used for every arithematic operation
    string pc;
    string start;
    vector<string>codeAddress;
    public :
        Emulator_8085(){
            for(int i=0;i<8;i++)    flags[i] = false; //Set all the flags to zero
            for(int i=0;i<4;i++){
                registers[i] = {"",""};
            }
            accumulator = "";
            pc = "";
            //Set all the register to null in start
        }

        void input(){
            cout<<"Enter a VALID START ADDRESS"<<endl;
            cin>>start;
            if(!validateAddress(start)){
                cout<<"The address entered is invalid or reserved by the processor"<<endl<<"Please Enter a valid address"<<endl<<"Program logging off"<<endl;
                exit(0);
            }
            else    codeAddress.push_back(start);
        }

};

int main(){
    Emulator_8085 machine;
    machine.input();
    string filename("input.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    while (getline(input_file, line)){
        lines.push_back(line);
    }
    input_file.close();
}