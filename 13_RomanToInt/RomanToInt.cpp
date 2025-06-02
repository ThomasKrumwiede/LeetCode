//Clonvert roman numerals to integers 
#include <iostream>
#include <string>

using namespace std;

//Calls to contain the romanToInt method 
class Solution {
    public:

        //function to turn a roman numeral to an int 
        int romanToInt(string s){
            int total = 0;
        
            //Loop through the entire stirn 
            for (int i = 0; i < s.length(); i++){
                //Case 1: subtraction in required 
                if (i + 1 < s.length() && testSubtraction(s[i], s[i + 1])){
                    total += charToInt(s[i + 1]) - charToInt(s[i]);
                    i++;
                } 
                //Case 2: only addition is needed 
                else{
                    total += charToInt(s[i]);
                }
            }
    
            return total;
        }

        //Method to convet a roman numeral to an interger
        int charToInt(char c){
            int value = 0;

            switch(c){
                case 'I':
                    value = 1;
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'X':
                    value = 10;
                    break;
                case 'L':
                    value = 50;
                    break;
                case 'C':
                    value = 100;
                    break;
                case 'D':
                    value = 500;
                    break;
                case 'M':
                    value = 1000;
                    break;
            }
            
            return value;
        }

        //test if subtraction is needed
        bool testSubtraction(char current, char next){
            //Conditions where subtraction is required 
            if (current == 'I' && (next == 'V' || next == 'X')) return true;
            if (current == 'X' && (next == 'L' || next == 'C')) return true;
            if (current == 'C' && (next == 'D' || next == 'M')) return true;

            //if non are true there is no subtraction needed 
            return false;
        }
    };

    
//Main function to test 
int main(){
    Solution test;
    cout << "test IV: " << test.romanToInt("IV") << endl;
    cout << "test XVI: " << test.romanToInt("XVI") << endl;

    return 0;
}