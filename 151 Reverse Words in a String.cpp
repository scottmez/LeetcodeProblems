class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        bool isWord = false;
        string sRev = "";
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) != ' ') {
                if (isWord == false) { //new word found
                    words.push_back(sRev + s.at(i)); 
                    isWord = true;
                }
                else { //add to current word
                    words.back() = words.back().append(sRev + s.at(i));
                }
            }
            else { //if (s.at(i) == ' '){
                isWord = false;
            }
        }

        sRev.append(words.back());
        for (int i = words.size() - 2; i >= 0; i--) {
            sRev.append(" ");
            sRev.append(words.at(i));
        } 
        return sRev;
    }
};