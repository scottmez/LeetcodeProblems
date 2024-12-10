class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        string sub = "";
        int minLen = strs.at(0).size();
        for (int i = 1; i < strs.size(); i++) { //find minLen
            if (strs.at(i).size() < minLen) {
                minLen = strs.at(i).size();
            }
        }
        char curC = ' ';
        for (int i = 0; i < minLen; i++) {
            curC = strs.at(0).at(i);
            for (int j = 1; j < strs.size(); j++) {
                if(strs.at(j).at(i) != curC) {
                    return strs.substr(0,i);
                }
            }
        }
    }
};