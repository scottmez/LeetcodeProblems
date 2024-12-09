class Solution {
public:
    int trap(vector<int>& height) {
        int heightL = height.front();
        int indexL = 0;
        int heightR = height.back();
        int indexR = height.size() - 1;
        int totalRain = 0;
        while (indexL != indexR) {
            if (heightL <= heightR) { //iterate heightL
                indexL++;
                if(height.at(indexL) < heightL) {
                    totalRain += (heightL - height.at(indexL));
                }
                else {
                    heightL = height.at(indexL);
                }
            }
            else { //iterate heightR
                indexR--;
                if(height.at(indexR) < heightR) {
                    totalRain += (heightR - height.at(indexR));
                }
                else {
                    heightR = height.at(indexR);
                }
            }
        }
        return totalRain;
    }
};