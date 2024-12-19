class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> letterCounts;
        for (int i = 0; i < ransomNote.size(); i++) {
            letterCounts[ransomNote.at(i)]++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            letterCounts[magazine.at(i)]--;
        }

        for(auto itr = letterCounts.begin(); itr != letterCounts.end(); ++itr) {
            if (itr->second > 0) {
                return false;
            }
        }
        
        return true;
    }
};