#include "./HeaderFiles/header.h"
#include "./HeaderFiles/datatransfer.h"
#include "./HeaderFiles/tools.h"
void increment(string& pc,int n){
    while(n){
        increaseAddress(pc);
        n--;
    }
}
void executeInstructions(string& pc,string& accumulator,string registers[], map<string, string>& memory, bool flags[]) {
	while (1) {
        vector<string>currCommand = divideInstruction(memory[pc]);
        for(auto it:currCommand)    cout<<it<<" ";
        cout<<endl;
        if(currCommand[0]=="HLT")   break;
		else if (currCommand[0] == "MOV") {
            cout<<currCommand[1]<<" "<<currCommand[2]<<endl;
			MOV(currCommand[1],currCommand[2],accumulator,registers,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "MVI") {
            increaseAddress(pc);
            string data = memory[pc];
            MVI(currCommand[1],accumulator,data,registers,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "LDA") {
            increaseAddress(pc);
            string address = memory[pc];
            increaseAddress(pc);
            address += memory[pc];
            LDA(address,accumulator,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "LDAX") {
            LDAX(currCommand[1],accumulator,registers,memory);
            increaseAddress(pc);            
		}
		else if (currCommand[0] == "LHLD") {
            increaseAddress(pc);
            string address = memory[pc];
            increaseAddress(pc);
            address += memory[pc];
            LHLD(address,registers,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "LXI") {
            increaseAddress(pc);
            string data = memory[pc];
            LXI(currCommand[1],data,registers,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "SHLD") {
            increaseAddress(pc);
            string address = memory[pc];
            increaseAddress(pc);
            address += memory[pc];
            SHLD(address,accumulator,registers,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "STA") {
            increaseAddress(pc);
            string address = memory[pc];
            increaseAddress(pc);
            address += memory[pc];
            STA(address,accumulator,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "STAX") {
            STAX(currCommand[1],accumulator,registers,memory);
            increaseAddress(pc);
		}
		else if (currCommand[0] == "XCHG") {
            XCHG(registers, memory);
            increaseAddress(pc);
		}
		// else if (currCommand[0] == "JC") {

		// }
		// else if (currCommand[0] == "JNC") {

		// }
		// else if (currCommand[0] == "JZ") {

		// }
		// else if (currCommand[0] == "JNZ") {

		// }
		// else if (currCommand[0] == "ANA") {

		// }
        // else if (currCommand[0] == "ANI") {

		// }
        // else if (currCommand[0] == "CMP") {

		// }
        // else if (currCommand[0] == "ORA") {

		// }
        // else if (currCommand[0] == "ORI") {

		// }
        // else if (currCommand[0] == "XRA") {

		// }
        // else if (currCommand[0] == "XRI") {

		// }
        // else{
        //     cout<<"Enter a valid command"<<endl;
        //     exit(0);
        // }
	}
}