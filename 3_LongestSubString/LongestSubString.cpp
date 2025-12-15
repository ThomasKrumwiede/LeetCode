#include<string>;
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp = "";
        int maxSize = 0;
        bool isrepeated; //track if there are any repeats 

        for(int i = 0; i < s.length(); i++){
            char currentLetter = s[i]; // get the current letter in the string 

            //Check if the letter is in the string 
            for (int j = 0; j < temp.length(); j++){
                //compare the value of temp with the currentLetter
                if(temp[j] == currentLetter){
                    isrepeated = true;
                    temp.erase(0, j + 1); //Remove all letters to the repeating char 
                }
            }

            temp.push_back(currentLetter);

            //Update size if needed 
            if (temp.length() > maxSize){
                maxSize = temp.length(); 
            }   
        }

        return maxSize;
    };
};