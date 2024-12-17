class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Given a string s, find the length of the longest substring without repeating characters.
        unsigned long maxLen = 0;
        set<char> mySet;
        
        unsigned long i = 0;
        unsigned long j = 0;
        for (j = 0 ; j < s.size(); j++) {
            while (mySet.count(s.at(j)) == 1) { 
                mySet.erase(s.at(i));
                i++;
            } 
            mySet.insert(s.at(j));
            maxLen = max(mySet.size(), maxLen);
        }
        return (int)maxLen;
    }
};