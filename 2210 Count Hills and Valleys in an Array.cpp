class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int state = -1;
        // 0 == hill
        // 1 == valley
        int prev = nums.at(0);
        for (int num : nums) {
            if (state == 0 && prev > num) {
                count++;
                state = 1;
            }
            else if (state == 1 && prev < num) {
                count++;
                state = 0;
            }
            else { //state == -1
                if (prev > num) {
                    state = 1;
                }
                else if (prev < num) {
                    state = 0;
                }
            }
            prev = num;
        }
        return count;
    }
};