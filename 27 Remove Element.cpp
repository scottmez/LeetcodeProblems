class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size() - 1; //keeps track of the end of the "good" array
        int temp; // used for swaps
        for (int i = nums.size() - 1; i > -1; i--) {
            if (nums[i] == val) {
                temp = nums[i];
                nums[i] = nums[k];
                nums[k] = temp;
                k--;
            }
        }
        return k + 1; //adjust for 0-indexing
    }
};