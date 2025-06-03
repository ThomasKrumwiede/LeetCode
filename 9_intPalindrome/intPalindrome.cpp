#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Function to be called in main to test if a number is a palindrome 
        bool isPalindrome(int x) {
            if (x < 0) return false;  // Negative numbers are not palindromes
    
            return x == reverse(x);
        }
    
        // Function to reverse the integer 
        int reverse(int x) {
            int rev = 0;
            while (x != 0) {
                int digit = x % 10;
    
                // Check for overflow
                if (rev > (INT32_MAX - digit) / 10) return 0;
    
                rev = rev * 10 + digit;
                x /= 10;
            }
            return rev;
        }
    };
    
    // Main function to test the class methods 
    int main() {
        Solution testCase;
    
        cout << "Test 1: " << testCase.isPalindrome(123) << "\n";  // Output: 0 (false)
        cout << "Test 2: " << testCase.isPalindrome(121) << "\n";  // Output: 1 (true)
        cout << "Test 3: " << testCase.isPalindrome(-121) << "\n"; // Output: 0 (false)
        return 0;
    }