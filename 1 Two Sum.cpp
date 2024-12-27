class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numToI;
        for (int i = 0; i < nums.size(); i++) {
            int res = target - nums.at(i);
            //if result is in map, use current index and index in map
            //otherwise put current index in map
            if(numToI.count(res)) {
                return {numToI[res], i};
            }
            numToI[nums.at(i)] = i;
        }

        return {-1, -1};

    }
};