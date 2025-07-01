#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    string testString1 = "Hello World";
    string testString2 = "   fly me   to   the moon  ";
    string testString3 = "luffy is still joyboy";

    //Test for string 1
    Solution Test1;
    cout << Test1.lengthOfLastWord(testString1) << endl;
    if(Test1.lengthOfLastWord(testString1) == 5) cout << "Test 1 Passes \n";

    //Test for string 2
    Solution Test2;
    cout << Test2.lengthOfLastWord(testString2) << endl;
    if(Test1.lengthOfLastWord(testString2) == 4) cout << "Test 2 Passes \n";

    //Test for string 3 
    Solution Test3;
    cout << Test3.lengthOfLastWord(testString3) << endl;
    if(Test1.lengthOfLastWord(testString3) == 6) cout << "Test 3 Passes \n";

    return 0;
}