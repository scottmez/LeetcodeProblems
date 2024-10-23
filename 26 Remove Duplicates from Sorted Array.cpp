class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0]; //previous element
        int num_distinct = 0; //keeps track of where to put the next distinct element
        int k = nums.size() - 1; //keeps track of the size of the final array
        for (int i = 1; i < nums.size(); i++){
            if (prev == nums[i]) {
                k--;
            }
            else {
                num_distinct++;
                nums[num_distinct] = nums[i]; //place the next distinct element in the correct position
            }
            prev = nums[i];
        }
        return k + 1; //adjust for 0-indexing
    }
};