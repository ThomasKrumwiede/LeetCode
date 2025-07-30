#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
    }

private:
    //method for getting the type of parentheses
    int parenthesesType(string s){
        int answer = 0; //will hold the return valaue 
        unordered_map<string, int> wordMap = {
        {"(", 1},
        {")", 1},
        {"{", 2},
        {"}", 2},
        {"[", 3},
        {"]", 3}
        };

         switch (wordMap[s]) {
            case 1:
                answer = 1;
                break;
            case 2: 
                answer = 2;
                break;
            case 3:
                answer = 3;
                break;
            }
        return answer;
    };
    

};