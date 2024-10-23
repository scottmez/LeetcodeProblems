class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k==0){
            return;
        }
        else {
            k = k % nums.size();
        }
        vector<int> nums2 = nums;
        for (int i = 0; i < nums.size(); i++) {
            int rotation = (i + k) % nums.size();
            nums[rotation] = nums2[i];
        }
    }
};