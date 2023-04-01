class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()==0) return true;
        int posS = 0;
        int n = t.size();
        for (size_t i = 0; i < n; i++) {
            if (s[posS] == t[i]) {
                posS++;
            }
        }
        if (posS < s.size()) {
            return false;
        }
        return true;
    }
};