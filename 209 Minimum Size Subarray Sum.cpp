class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
        [2,3,1,2,4,3]
        target = 7
        
        sums:
        2
        5
        6
        8
        6
        10
        7
        6
        9
        7
        3
        */


        int minLength = nums.size() + 1;
        int currSum = 0;

        unsigned long i = 0;
        unsigned long j = 0;
        for (j = 0; j < nums.size(); j++) { //increase window from the right
            currSum += nums.at(j); 
            //okay so we need this to help runtime
            //basically once we find a sum >= target we know the range is at maximum, 
            //that size, so only make sums of that size from now on
            while (currSum >= target) { //while curSum >= target, shrink window from the left
                if ((j - i) + 1 < minLength) {
                    minLength = (j - i) + 1;
                }
                currSum -= nums.at(i); // currSum = currSum - nums.at(i)
                i += 1;
            } 
        }

        if (minLength == nums.size() + 1) {
            return 0; //the entire array does not sum to the value
        }

        return minLength;
    }
};