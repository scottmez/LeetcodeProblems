class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int i = 0;
        int j = 0;
        int max = min(k, (int)(nums.size() - 1));
        for (j = 0; j <= max; j++) {
            if (m.count(nums[j]) > 0) {
                return true;
            }
            m[nums[j]] = j;
        }
        for (j = k + 1; j < nums.size(); j++) {
            m.erase(nums[i]);
            i++;
            if (m.count(nums[j]) > 0) {
                return true;
            }
            m[nums[j]] = j;
        }
        return false;
    }
};