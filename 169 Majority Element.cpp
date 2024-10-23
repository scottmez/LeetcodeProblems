//#include <unordered_map> //not needed for leetcode submission, so commented
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numToCount;
        for (int i = 0; i < nums.size(); i++) {
            if (numToCount.count(nums[i]) > 0) {
                numToCount[nums[i]] += 1;
            }
            else {
                numToCount.insert({nums[i], 1});
            }
        }
        int max = 0;
        int elem = 0;
        for (auto it = numToCount.cbegin(); it != numToCount.cend(); it++) {
            if (it->second > max) {
                max = it->second;
                elem = it->first;
            }
        }
        return elem;
    }
};