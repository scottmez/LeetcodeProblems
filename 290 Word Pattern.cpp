class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_map<string, char> rev_m;
        int indexL = 0;
        int p = 0;
        char unint = rev_m["0"]; //need to get uninitialized char character
        for (int i = 0; i < s.size(); i++) {
            bool check = false;
            int len = 0;
            if (s.at(i) == ' ') {
                check = true;
                len = i - indexL;
            }
            else if (i == s.size() - 1) {
                check = true;
                len = i + 1 - indexL;
            }
            if(check) {
                //attempt to insert into map 
                //if map contains pair, then check it
                string sub = s.substr(indexL, len);
                //cout << rev_m[sub] << endl;
                if ((m[pattern[p]] != "" && m[pattern[p]] != sub) || (rev_m[sub] != unint && rev_m[sub] != pattern[p])) { //if theres a duplicate key and the keys map to different values
                    return false;
                }
                m[pattern[p]] = sub;
                rev_m[sub] = pattern[p];
                indexL = i + 1;
                p++;
            }
        }
        
        if (p != pattern.size()) {
            return false;
        }
        return true;
    }
};