class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> output;
            if (nums.size() == 0) {
                return output;
            }
            int first = nums.front();
            int last = nums.back();
            for (int i = 1; i < nums.size(); i++) {
                if  (nums[i] != nums[i-1]+1) {
                    //we are not in a range
                    last = nums[i-1];
                    if (first == last) {
                        //previous range was a single number
                        output.push_back(to_string(first));
                    }
                    else {
                        //previous range had at least 2 numbers
                        output.push_back(to_string(first) + "->" + to_string(last));
                    }
                    first = nums[i];
                } 
                //else we are in a range and dont need to do anything
                last = nums[i];
            }
            //check end of array
            if (first == last) {
                output.push_back(to_string(first));
            }
            else {
                output.push_back(to_string(first) + "->" + to_string(last));
            }

            return output;
        }
    };