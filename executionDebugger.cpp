#include "./HeaderFiles/header.h"
#include "./HeaderFiles/tools.h"
    void printCode(string pc){
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
void displayHelp()
{
	string filename("help.txt");
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
		cout << line << endl;
	}
}
void executionDebugger(string &pc, string &accumulator, map<string, string> &memory, bool flags[], string registers[])
{
	displayHelp();
	string option;
	vector<string> breakpoints;
	cout << "Enter Options:-\n";
	while (true)
	{
		cout << "-> ";
		cin >> option;
		if (option == "-h" || option == "help")
		{
			displayHelp();
		}
		else if (option == "-pc")
		{

			cout << "Program counter --> " << pc << "\n";
		}
		else if (option == "-p" || option == "print")
		{
			string valueHolder;
			cin >> valueHolder;
			cin.ignore();
			int l = valueHolder.length();
			if (l == 1)
			{
				if (validateRegister(valueHolder))
					cout << registers[registerNumber(valueHolder)] << "\n";
				else if(valueHolder == "A")	
					cout << accumulator << "\n";
				else
					cout << "Error: " << valueHolder << " You have entered invalid register name\n"
						 << "Type 'help' for more information\n";
			}
			else if (l == 4)
			{
				if (validateAddress(valueHolder))
				{
					cout << "                  --------" << endl;
					cout << valueHolder << "-> |" << memory[valueHolder] << "|\n";
					cout << "                  --------" << endl;
				}
				else
					cout << "Error: " << valueHolder << " You have entered invalid address\n"
						 << "Type 'help' for more information\n";
			}
			else
				cout << "Error: " << valueHolder << "\nType 'help' for more information\n";
		}
		else if (option == "-b" || option == "break")
		{
			printCode(pc);
			cout << "Set a break point according to the Code address" << endl;
			string lineNumber;
			cin >> lineNumber;
			breakpoints.push_back(lineNumber);
		}
		else if (option == "-s" || option == "step")
		{
			cout<<"Executed the command : "<<memory[pc]<<endl;
			if (pc != "")
				execute(pc, accumulator, registers, memory, flags);
			display(accumulator, registers, flags);
		}
		else if (option == "-r" || option == "run")
		{
			cout<<"Enter Run mode"<<endl;
			if (pc != "")
			{
				if (breakpoints.empty())
				{
					while (true)
					{
						if (memory[pc] == "HLT")
						{
							pc = "";
							break;
						}
						else
						{
							execute(pc, accumulator, registers, memory, flags);
						}
						display(accumulator, registers, flags);
					}
				}
				else
				{
					if (validateAddress(breakpoints[0]))
					{
						pc = breakpoints[0];
						execute(pc, accumulator, registers, memory, flags);
						display(accumulator, registers, flags);
					}
					else
					{
						cout << "Enter a valid breakpoint" << endl;
					}
				}
			}
			else
			{
				char choice = '\0';
				cout << "You have reached till the end of execution. Press to continue[Y/n] ";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					continue;
				}
				else if (choice == 'N' || choice == 'n')
					exit(0);
				else
					cout << "Please input correct option\n";
				continue;
			}
		}
		else if (option == "-q" || option == "quit")
			break;
		else
		{
			cout << "Invalid choice has been entered. Type 'help' for more information about debugger\n";
		}
	}
}