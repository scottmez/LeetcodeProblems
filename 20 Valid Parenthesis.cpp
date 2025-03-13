class Solution {
    public:
        bool isValid(string s) {
            map<char, char> endToStart = {{'}','{'},{')','('},{']','['}};
            stack<char> parens;
            for (int i = 0; i < s.size(); i++) {
                if (s.at(i) == ')' || s.at(i) == '}' || s.at(i) == ']') { //if its a closing parenthesis and the parens match type
                    if (parens.size() > 0 && parens.top() == endToStart.at(s.at(i))) {
                        parens.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    parens.push(s.at(i));
                }
            }
            
            if (parens.size() > 0) {
                return false;
            }

            return true;
        }
    };