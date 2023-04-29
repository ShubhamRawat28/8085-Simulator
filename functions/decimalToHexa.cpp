#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

string decimalToHexa(int n){
        // ans string to store hexadecimal number
    string ans = "";
    
    while (n != 0) {
        // remainder variable to store remainder
        int rem = 0;
          
        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;
  
        // check if temp < 10
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
          
        // updating the ans string with the character variable
        ans += ch;
        n = n / 16;
    }
      
    // reversing the ans string to get the final result
    reverse(ans.begin(),ans.end());
    return ans;
}
