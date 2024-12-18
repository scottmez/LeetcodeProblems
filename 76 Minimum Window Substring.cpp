class Solution {
public:
    string minWindow(string s, string t) {
        /*
        Given two strings s and t of lengths m and n respectively, return the minimum window substring
        of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

        The testcases will be generated such that the answer is unique.
        */

        //can't use a set because "(including duplicates)"
        // set can only record 1 or 0 instances of a char
        //need a map to show 'c' : 1, 'b': 2, etc.

        if (s.size() < t.size()) {
            return "";
        }

        map<char, int> charCount;

        pair<int,int> minWindow = {0, s.size() + 1};
        int targetCharacterRemaining = t.size();
        unsigned int i = 0;
        unsigned int j = 0;

        for (i = 0; i < t.size(); i++) {
            charCount[t.at(i)]++;
        }

        i = 0;
        for (j = 0; j < s.size(); j++) { //j is right index, i will be left

            if (charCount[s.at(j)] > 0){ //if we need the next character
                targetCharacterRemaining -= 1;
            }
            charCount[s.at(j)] -= 1; //in any case decrement count, cause we have it now
            
            while(targetCharacterRemaining == 0) {
                if (minWindow.second - minWindow.first > j - i) {
                    minWindow = {i, j};
                }
                charCount[s.at(i)] += 1;
                if (charCount[s.at(i)] > 0) {
                    targetCharacterRemaining += 1;
                }
                i += 1;
            }
            
            
        }

        if (minWindow.second > s.size()) {
            return "";
        }

        return s.substr(minWindow.first, minWindow.second - minWindow.first + 1);

    }
};