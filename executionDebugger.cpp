#include "./HeaderFiles/header.h"
#include "./HeaderFiles/tools.h"

void executionDebugger(string &pc, string &accumulator, map<string, string> &memory, bool flags[], string registers[])
{
	string option;
	vector<int> breakpoints;
	cout << "Enter Options:-\n";
	while (true)
	{
		cout << "-> ";
		cin >> option;
		if (option == "-h" || option == "help")
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
				cout<<line<<endl;
			}
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
				else
					cout << "Error: " << valueHolder << " You have entered invalid register name\n"
						 << "Type 'help' for more information\n";
			}
			else if (l == 4)
			{
				if (validateAddress(valueHolder))
					cout << memory[valueHolder] << "\n";
				else
					cout << "Error: " << valueHolder << " You have entered invalid address\n"
						 << "Type 'help' for more information\n";
			}
			else
				cout << "Error: " << valueHolder << "\nType 'help' for more information\n";
		}
		else if (option == "-b" || option == "break")
		{
			cout << "Set a break point according to the Code address" << endl;
			int lineNumber;
			cin >> lineNumber;
			breakpoints.push_back(lineNumber);
		}
		else if (option == "-s" || option == "step")
		{
			if (pc != "")
				execute(pc, accumulator, registers, memory, flags);
		}
		else if (option == "-r" || option == "run")
		{
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
							execute(pc, accumulator, registers, memory, flags);
					}
				}
				else
				{
					execute(pc, accumulator, registers, memory, flags);
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
			display(accumulator,registers,flags);
		}
		else if (option == "-q" || option == "quit")
			break;
		else
		{
			cout << "Invalid choice has been entered. Type 'help' for more information about debugger\n";
		}
	}
}