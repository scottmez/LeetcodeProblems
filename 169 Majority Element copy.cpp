class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mostCommon = 0;
        int frequency = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (frequency == 0) {
                mostCommon = nums[i];
            }
            if (mostCommon == nums[i]) {
                frequency++;
            }
            else {
                frequency--;
            }
        }
        return mostCommon;
    }
};