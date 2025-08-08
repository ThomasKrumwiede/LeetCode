#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> corrospondingLetters; //This holds the letters that corrospond to the sting of digits 
        vector<string> returnVector; //This holds the answer to be returned 

        if (digits == "") return returnVector; //In the event that no digits were entered 

        //In the case where there is only one digit
        if (digits.length() == 1){
            string temp = digitLetters(digits[0]);
            for (char c : temp){
                returnVector.push_back(string(1, c));
            }
            return returnVector;
        }

        //In the case where there are multiple digits 
        for(int i = 0; i < digits.length() ; i++){
            char temp = digits[i];
            string inputValue = digitLetters(temp);
            corrospondingLetters.push_back(inputValue);
        }
        while 
      
    }

    //function to turn the digits to the carosponding letters 
    string digitLetters(char digit){
        string letters;
        int value = digit - '0';

        switch (value){
            case 2:
                letters = "abc";
                break;
            case 3:
                letters = "def";
                break;
            case 4:
                letters = "ghi";
                break;
            case 5:
                letters = "jkl";
                break;
            case 6:
                letters = "mno";
                break;
            case 7:
                letters = "pqrs";
                break;
            case 8:
                letters = "tuv";
                break;
            case 9:
                letters = "xyz";
                break;
        }

        return letters;
    }
    
};