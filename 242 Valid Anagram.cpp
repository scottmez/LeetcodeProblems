class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s.at(i)]++;
        }
        for (int i = 0; i < s.size(); i++) {
            m[t.at(i)]--;
        }
        for (auto itr = m.begin(); itr != m.end(); ++itr) {
            if (itr->second != 0) {
                return false;
            }
        }
        return true;
    }
};