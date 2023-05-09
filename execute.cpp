#include "./HeaderFiles/header.h"
#include "./HeaderFiles/datatransfer.h"
#include "./HeaderFiles/tools.h"
#include "./HeaderFiles/logical.h"
#include "./HeaderFiles/arithematic.h"
#include "./HeaderFiles/branching.h"

void execute(string &pc, string &accumulator, string registers[], map<string, string> &memory, bool flags[])
{
    vector<string> currCommand = divideInstruction(memory[pc]);
    if (currCommand[0] == "HLT")
		return;
    else if (currCommand[0] == "MOV")
    {
          cout << currCommand[1] << " " << currCommand[2] << endl;
          MOV(currCommand[1], currCommand[2], accumulator, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "MVI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          MVI(currCommand[1], accumulator, data, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "LDA")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          LDA(address, accumulator, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "LDAX")
    {
          LDAX(currCommand[1], accumulator, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "LHLD")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          LHLD(address, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "LXI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          LXI(currCommand[1], data, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "SHLD")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          SHLD(address, accumulator, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "STA")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          STA(address, accumulator, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "STAX")
    {
          STAX(currCommand[1], accumulator, registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "XCHG")
    {
          XCHG(registers, memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "JC")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          JC(address, pc, flags);
    }
    else if (currCommand[0] == "JNC")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          JNC(address, pc, flags);
    }
    else if (currCommand[0] == "JZ")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          JZ(address, pc, flags);
    }
    else if (currCommand[0] == "JNZ")
    {
          increaseAddress(pc);
          string address = memory[pc];
          increaseAddress(pc);
          address += memory[pc];
          JNZ(address, pc, flags);
    }
    else if (currCommand[0] == "ANA")
    {
          ANA(currCommand[1],accumulator,registers,memory,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "ANI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          ANI(data,accumulator,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "CMA")
    {
          CMA(accumulator);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "ORA")
    {
          ORA(currCommand[1],accumulator,registers,memory,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "ORI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          ORI(data,accumulator,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "XRA")
    {
          XRA(currCommand[1],accumulator,registers,memory,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "XRI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          XRI(data,accumulator,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "ADD")
    {
          ADD(currCommand[1],accumulator,registers,flags,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "ADI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          ADI(data,accumulator,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "CMP")
    {
          CMP(currCommand[1],registers,accumulator,flags,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "DAD")
    {
          DAD(currCommand[1],registers,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "DCR")
    {
          DCR(currCommand[1],registers,accumulator,flags,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "DCX")
    {
          DCX(currCommand[1],registers,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "INR")
    {
          INR(currCommand[1],registers,accumulator,flags,memory);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "INX")
    {
          INX(currCommand[1],registers,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "SBI")
    {
          increaseAddress(pc);
          string data = memory[pc];
          SBI(data,accumulator,registers,flags);
          increaseAddress(pc);
    }
    else if (currCommand[0] == "SUB")
    {
          SUB(currCommand[1],accumulator,registers,flags,memory);
          increaseAddress(pc);
    }
    else
    {
          cout << "Enter a valid command" << endl;
          exit(0);
    }
}