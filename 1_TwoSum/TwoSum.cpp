#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<int> answer;
        bool foundFlag = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    foundFlag = 1;
                }
                if (foundFlag == 1) break;
            }
            if (foundFlag == 1) break;
        }
        return answer;
    }
};