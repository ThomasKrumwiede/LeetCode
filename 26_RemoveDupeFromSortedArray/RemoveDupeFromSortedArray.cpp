//Leet code problme 26: Remove Duplicates from Sorted Array 
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>

using namespace std;

//contains method to remove duplicates 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //First constraint: Length 
        if (1 <= nums.size() && nums.size() >= 30000) throw runtime_error("Incompatible array size");
        
        //variables to hold the current and previous value
        int previous;
        int current; 
        //Iterate throught the vector and check for and remove duplicates 
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
            } 
            else {
                i++;
            }
        }
        return nums.size();
    }
};


int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    vector<int> expected1 = {1, 2};
    int k1 = sol.removeDuplicates(nums1);

    assert(k1 == expected1.size());
    for (int i = 0; i < k1; ++i) {
        assert(nums1[i] == expected1[i]);
    }
    cout << "Test 1 passed. k = " << k1 << ", result: ";
    for (int i = 0; i < k1; ++i) cout << nums1[i] << " ";
    cout << "\n";

    //Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> expected2 = {0, 1, 2, 3, 4};
    int k2 = sol.removeDuplicates(nums2);

    assert(k2 == expected2.size());
    for (int i = 0; i < k2; ++i) {
        assert(nums2[i] == expected2[i]);
    }
    cout << "Test 2 passed. k = " << k2 << ", result: ";
    for (int i = 0; i < k2; ++i) cout << nums2[i] << " ";
    cout << "\n";

    return 0;
}