class Solution {
public:
    int uniquePaths(int m, int n) {
        //given n x m grid find # of unique paths from top left to bottom right 
        // n is across, m is down (n is size of each array, m is number of arrays)
        // restriction: you can only move down and right
        // dynamic programming

        vector<vector<int> > grid;
        vector<int> begin (1,1);

        //initialize grid
        for (int i = 0; i < m; i++) {
            grid.push_back(begin);
            for (int j = 1; j < n; j++) {
                grid.at(i).push_back(0);
            }
        }
        for (int j = 1; j < n; j++) {
            grid.at(0).at(j) = 1;
        }

        //traverse grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid.at(i).at(j) += grid.at(i).at(j-1) + grid.at(i-1).at(j);
            }
        }

        return grid.back().back();
    }
};