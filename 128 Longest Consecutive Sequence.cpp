class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //I use two maps, one that maps start to length and one that maps end to length
        int longest = 0;
        map<int,int> startLen;
        map<int,int> endLen;
        unordered_set<int> numbs (nums.begin(), nums.end());

        for (const auto& num: numbs) {
            cout << num << endl;
            startLen[num] = 1;
            endLen[num] = 1;
            bool isNewStart = false;
            if (startLen[num+1] > 0) {  //can we add this number to the start of an existing chain?
                startLen[num] = startLen[num+1] + 1;
                endLen[num+startLen[num] - 1] += 1;
                isNewStart = true;
                longest = max(startLen[num],longest);
            }
            if (endLen[num-1] > 0) { //can we add it the the end of a chain
                if (isNewStart) {//combine time
                    startLen[num - endLen[num - 1]] += 1 + startLen[num+1]; //add start of one, plus self, plus start of next
                    endLen[num + startLen[num + 1]] = startLen[num - endLen[num - 1]];
                    longest = max(startLen[num - endLen[num - 1]], longest);
                }
                else {
                    endLen[num] = endLen[num - 1] + 1;
                    startLen[num - endLen[num] + 1] += 1;
                    longest = max(endLen[num], longest);
                }
            }
        }
        
        return longest;
     }
};