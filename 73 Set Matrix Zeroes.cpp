class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> cols; //columns to fill
        set<int> rows; //rows to fill
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                if (matrix.at(i).at(j) == 0) {
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }
        for (auto itr = rows.begin(); itr != rows.end(); ++itr) {
            int j = *itr;
            for(int col = 0; col < matrix.at(0).size(); col++) {

            }
        }

        for (auto itr = cols.begin(); itr != cols.end(); ++itr) {
            int i = *itr;
            for(int row = 0; row < matrix.size(); row++) {
                
            }
        }
    }
};