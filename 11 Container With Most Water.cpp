class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        int max = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                if ( min(height.at(i), height.at(j)) * (j - i) > max ) {
                    max = min(height.at(i), height.at(j)) * (j - i);
                }
            }
        }
        return max;
        */
        //^TLE
        //we need some way to get more information, so we can shrink the problem space
        /*
        its intuitive that heights that are further apart often have large areas because A = w x h
        and the width is larger when the heights are further apart
        We should try to record some information as we go through the problem so we can end earlier
        for example if we see that our max is 40 and we know that the last two heights are lower than 40 then we can stop
        because they would need to both be higher than 40 to get a new max
        
        
        */

        int indexL = 0;
        int indexR = height.size() - 1;
        int m = 0;

        while(indexL != indexR) {
            m = max(min(height.at(indexL), height.at(indexR)) * (indexR - indexL), m);

            if (height.at(indexL) < height.at(indexR)) {
                indexL++;
            }
            else {
                indexR--;
            }
        }
       

        return m;
    }
};