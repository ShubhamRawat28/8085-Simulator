#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

/*Carry flag remains unaffected in INR and DCR operations*/

string hexaAdd(string arg1,string accumulator,bool flag[],bool carry){

	string resultant = "";
	int variable;
	int value1[5] = {0,0};
	int value2[5] = {0,0};
	int tempAnswer[2];
	/*Convert hexadecimal data to decimal*/
	hexaToDecimal(arg1,value1);
	hexaToDecimal(accumulator,value2);

	tempAnswer[1] = value1[1] + value2[1];
	if(tempAnswer[1]>15){
		tempAnswer[1] = tempAnswer[1]%16;
		value1[0]++;
		flag[4] = true;
		}
	tempAnswer[0] = value1[0] + value2[0];
	if(tempAnswer[0]>15){
		tempAnswer[0] = tempAnswer[0]%16;
		// if(carry == true)
			flag[0] = true;
	}
	
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	/*Setting parity flag*/
	int parity = dataInBinary.count();
	if(parity%2 == 0 )
		flag[2] = true;
	else
		flag[2] = false;
	/*Setting sign flag*/
	flag[7] = dataInBinary[7];
	/*Setting zero flag*/
	if(parity == 0)
		flag[6] = true;
	
	/*Convert decimal data to hexadecimal and store in accumulator*/
	for(int i = 1;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0' + tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	
	return resultant;

}
