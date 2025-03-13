class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            //sorted by start of interval
            
            intervals.push_back(newInterval);

            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

            //sort by start of interval
            vector<vector<int>> output;
            output.push_back(intervals[0]);
            int numIntervals = intervals.size();
            for (int i = 1; i < numIntervals; i++) {
                if (output.back()[1] >= intervals[i][0]) {
                    //we need to merge
                    output.back()[1] = max(output.back()[1], intervals[i][1]); 
                } 
                else {
                    //no merge
                    output.push_back(intervals[i]);
                }
            }
            return output;
        }
    };