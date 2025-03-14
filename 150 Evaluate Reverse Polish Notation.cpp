class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> s;
            int arg1;
            int arg2;
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens[i] == "/") {
                    arg2 = s.top();
                    s.pop();
                    arg1 = s.top();
                    s.pop();
                    s.push(arg1/arg2);
                }
                else if (tokens[i] == "+") {
                    arg2 = s.top();
                    s.pop();
                    arg1 = s.top();
                    s.pop();
                    s.push(arg1+arg2);
                }
                else if (tokens[i] == "-") {
                    arg2 = s.top();
                    s.pop();
                    arg1 = s.top();
                    s.pop();
                    s.push(arg1-arg2);
                }
                else if (tokens[i] == "*") {
                    arg2 = s.top();
                    s.pop();
                    arg1 = s.top();
                    s.pop();
                    s.push(arg1*arg2);
                }
                else {
                    s.push(stoi(tokens[i]));
                }
            }
        }
    };