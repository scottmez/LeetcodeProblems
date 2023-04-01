class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m = {};
        unordered_map<char,char> rev_m = {};
        int n = s.size();
        for (size_t i = 0; i < n; i++) {
            if (m.count(s[i]) == 0) {
                if (rev_m.count(t[i]) == 0) { 
                    m.insert({s[i],t[i]});
                    rev_m.insert({t[i],s[i]});
                }
                else 
                    return false;
            }
            else {
                if (m.at(s[i]) == t[i]) 
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};