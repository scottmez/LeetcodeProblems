class Solution {
public:
    int lengthOfLastWord(string s) {
        //return the length of the last word in the string
        int start = -1; //so if we just get a word with no spaces (e.g. "how") 2 - (-1) = 3
        int end = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s.at(i) == ' ' && end != 0) { //if its a space, cut off there
                start = i;
                return end - start;
            }
            else if (isalpha(s.at(i)) && end == 0 ) { //from cctype header, checks if in alphabet
                end = i;
            }
        }
        return end - start;
    }
};