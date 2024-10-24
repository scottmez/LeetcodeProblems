//#include <vector>
//#include <algorithm>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> canBe(nums.size(), false); //initialize a vector of bools of length nums.size() where every value is false
        canBe[0] = true; //we start at the first position so we "can be" there
        queue<int> toDo;
        toDo.push(0);
        while(!toDo.empty()) {
            int index = toDo.front();
            toDo.pop();
            int numToJump = nums[index];
            nums[index] = 0; //this makes sure we wont repeat the check at any index in nums, but assumes we dont need the input array after this function
            if (index + numToJump >= nums.size() - 1) {
                return true;
            }
            for (int i = 1; i <= numToJump; i++) {
                int nextIndex = i + index;
                canBe[nextIndex] = true;
                toDo.push(nextIndex);
            }
        }
        return canBe[nums.size()-1];
    }
};