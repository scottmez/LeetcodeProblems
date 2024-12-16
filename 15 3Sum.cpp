class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //kinda like 2-sum but we have some static "extra" amount from the third value
        //basically we do 2 sum, k times
        vector<vector<int> > sums;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) { // subtract 2 cause we have 2 other indeces
            if (i > 0 && nums.at(i) == nums.at(i-1)) { //avoids duplicates
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums.at(i) + nums.at(j) + nums.at(k);
                if (sum == 0) {
                    sums.push_back({nums.at(i), nums.at(j), nums.at(k)});
                    int jval = nums.at(j);
                    j += 1;
                    while(jval == nums.at(j) && j < k) {
                        j += 1;
                    }
                }
                else if (sum < 0) {
                    j++;
                } 
                else { //sum > 0
                    k--;
                }
            }
        }
        return sums;
    }
};