class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); i++) {
            nums.at(i) = nums.at(i) + nums.at(i-1);
        }
        return nums;
    }
};