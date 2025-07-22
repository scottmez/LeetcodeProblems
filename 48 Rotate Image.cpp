class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for (int i = 0; i < (n + 1)/2; i++)  {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix.at(i).at(j);
                int ind = i;
                int jnd = j;
                for (int k = 0; k < 4; k++) { //since we are rotating 90 degrees we can break things up into 4 parts (4*90 = 360)
                    swap(ind, jnd);
                    jnd = (n-1) - jnd;
                    swap(temp, matrix.at(ind).at(jnd));
                }
            }
        }
    }
};