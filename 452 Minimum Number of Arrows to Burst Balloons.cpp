class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

            if (points.size() == 1) {
                return 1;
            }
            int merges = 0;
            for (int i = points.size() - 1;  i > 0; i--) {
                if(points[i][0] <= points[i-1][1]) {
                    //combine by finding the max of the starts and the min of the ends
                    merges += 1;
                    //b/c we sorted max is guaranteed to be points[i][0]
                    points[i-1][0] = points[i][0]; // max(points[i-1][0], points[i][0]);
                    points[i-1][1] = min(points[i-1][0], points[i][0]);
                }
            }

            return points.size() - merges;
            
        }
    };