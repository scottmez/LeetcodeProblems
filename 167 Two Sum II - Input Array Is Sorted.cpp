class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int indexSmall = 0;
        int indexLarge = numbers.size() - 1;
        vector<int> indeces (2, indexSmall);
        
        while(indexSmall != indexLarge) {
            if (numbers.at(indexSmall) + numbers.at(indexLarge) > target) {
                indexLarge--;
            }
            else if (numbers.at(indexSmall) + numbers.at(indexLarge) < target) {
                indexSmall++;
            }
            else { // (numbers.at(indexSmall) + numbers.at(indexLarge) == target) 
                indeces.at(0) = indexSmall;
                indeces.at(1) = indexLarge;
                return indeces;
            }
        }
        //shouldnt happen
        return indeces;
    }
};