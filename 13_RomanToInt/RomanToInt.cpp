//Clonvert roman numerals to integers 
#include <iostream>
#include <string>

using namespace std;

//Calls to contain the romanToInt method 
class Solution {
    public:
        int romanToInt(string s) {
            int total = 0;  //Hold the total integer value 
            char current;   //Hold the current letter
            char next;      //Hold the next letter

            //For only a single roman numeral 
            if (s.length() == 1) return charToInt(s[0]); 

            //loop throuhg the entier string 
            for(int i = 0; i + 1 < s.length(); i++){
                current = s[i];
                next = s[i+1];

                //Case 1: subtraction is needed
                if (testSubtraction(current, next)){
                    total += (charToInt(next) - charToInt(current));
                    i++;
                }
                //Case 2: no subtraction needed 
                else{
                    total += charToInt(current); 
                }
                
                
                cout << "Current " << current;
                cout << "Next " << next;
            }
            return total;
        }

        //Method to convet a roman numeral to an interger
        int charToInt(char c){
            if (c == 'I') return 1;
            if (c == 'V') return 5;
            if (c == 'X') return 10;
            if (c == 'L') return 50;
            if (c == 'C') return 100;
            if (c == 'D') return 500;
            if (c == 'M') return 1000;
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
    test.romanToInt("IV");

    return 0;
}