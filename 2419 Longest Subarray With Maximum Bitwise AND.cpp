class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //largest bitwise AND is just the largest number, k
        //find the length of the longest subarray equal to k
        int largest = INT_MIN;
        for (int num : nums) {
            largest = max(largest, num);
        }

        int max_len = 1; //since we know we've already seen the largest number at least once
        int cur_len = 0;
        for (int num : nums) {
            if (num == largest) {
                cur_len += 1; 
            }
            else {
                cur_len = 0;
            }
            max_len = max(cur_len, max_len);
        }
    }
};