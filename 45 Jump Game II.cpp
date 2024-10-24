class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minJumps(nums.size(), nums.size());
        minJumps[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            int jumpLen = min(nums[i], (nums.size() - 1) - i);
            for (int j = 1; j <= jumpLen; j++) {
                minJumps[j + i] = min(minJumps[i] + 1, minJumps[j+i]);
            }
        }
        return minJumps[nums.size()-1];
    }

    int min(int a, int b) {
        return (a<b)?a:b;
    }
};