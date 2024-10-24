//#include <vector>
//#include <algorithm>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> canBe(nums.size(), false); //initialize a vector of bools of length nums.size() where every value is false
        canBe[0] = true; //we start at the first position so we "can be" there
        for(int i = 0; i < nums.size(); i++) {
            if (!canBe[i]) {
                continue;
            }
            int numToJump = nums[i];
            if (i + numToJump >= nums.size() - 1) {
                return true;
            }
            for (int j = 0; j <= numToJump; j++) {
                int nextIndex = j + i;
                canBe[nextIndex] = true;
            }
        }
        return canBe[nums.size()-1];
    }
};