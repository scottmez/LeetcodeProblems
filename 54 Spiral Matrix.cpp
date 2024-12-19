class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) {
            return matrix.at(0);
        }
        vector<int> result;
        if (matrix.at(0).size() == 1) {
            for (int i = 0; i < matrix.size(); i++) {
                result.push_back(matrix.at(i).at(0));
            }
            return result;
        }
        map<int, int> counterToX = {{0, 0},{1, 1},{2, 0},{3, -1}};
        map<int, int> counterToY = {{0, -1},{1, 0},{2, 1},{3, 0}};
        
        int elements = 0;
        int i = 0; //y
        int j = 0; //x
        int n = matrix.size(); //y
        int m = matrix.at(0).size(); //x
        int counter = 1;
        int counterM = counter; 
        int beginPad = 1;
        int endPad = 0;
        while (elements < matrix.size()*matrix.at(0).size()) {
            int end = max(( (abs(counterToX[counterM]) * m) + (abs(counterToY[counterM]) * n) ) - endPad, beginPad+1);
            for (int k = beginPad; k < end; k++) { //need to increment 
                result.push_back(matrix.at(i).at(j));
                elements++;
                j += counterToX[counterM];
                i += counterToY[counterM];
            }

            counter += 1;
            beginPad = (counter + 2)/4;
            endPad = counter / 4;

            counterM = counter % 4;
        }
        return result;
    }
};