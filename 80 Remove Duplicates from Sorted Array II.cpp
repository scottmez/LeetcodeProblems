class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0]; //previous element
        int next_index = 0; //keeps track of where to put the next distinct element
        int dup_counter = 1;
        int k = nums.size() - 1; //keeps track of the size of the final array
        for (int i = 1; i < nums.size(); i++){
            if (prev == nums[i]) {
                dup_counter++;
                if(dup_counter > 2) {
                    k--;//shortens the returned array size when there are more than 2 of any element
                }
                else {
                    nums[next_index + dup_counter - 1] = nums[i];// handles case where we want to keep a single copy of an element
                }
            }
            else{
                next_index += (2 < dup_counter) ? 2 : dup_counter; //min(2,dup_counter)
                nums[next_index] = nums[i]; //place the next distinct element in the correct position
                dup_counter = 1;
            }
            prev = nums[i];
        }
        return k + 1; //adjust for 0-indexing  
    }
};