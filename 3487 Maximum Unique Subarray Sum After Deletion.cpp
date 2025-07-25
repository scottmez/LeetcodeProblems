class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        int sum = 0;
        int max_num = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i]) == 0) {
                max_num = max(max_num, nums[i]);
                if (nums[i] > 0) {
                    s.insert(nums[i]);
                    sum += nums[i];
                }
            }
        }
        if (s.size() == 0) {
            return max_num;
        }
        return sum;
    }
};