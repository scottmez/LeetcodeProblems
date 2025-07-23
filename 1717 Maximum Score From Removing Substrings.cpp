class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //remove "ab" for x points
        //remove "ba" for y points
        //Find maximum earnable points 

        char first = 'a';
        char second = 'b';
        int largerPoints = x;
        int smallerPoints = y;

        if (x < y) {
           first = 'b';
           second = 'a';
           largerPoints = y;
           smallerPoints = x;
        }

        int points = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s.at(i-1) == first && s.at(i) == second) {
                points += largerPoints;
                s.erase(i-1,2);
                i = max(0, i - 2);
            }
        }

        for (int i = 1; i < s.size(); i++) {
            if (s.at(i-1) == second && s.at(i) == first) {
                points += smallerPoints;
                s.erase(i-1,2);
                i = max(0, i - 2);
            }
        }

        return points;
    }
};