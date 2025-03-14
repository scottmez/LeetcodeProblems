class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> sta;
            string str = "";
            for (int i = 0 ; i < path.size(); i++) {
                if (path[i] == '/') {
                    if (str.size() > 0) {
                        if(str == ".." && sta.size() > 0) {
                            sta.pop();
                        }
                        else if (str != "." && str != "..") {//dont add "."
                            sta.push(str);
                        }
                    }
                    str = "";
                }
                else {
                    str += path[i];
                }
            }

            if(str == "..") {
                if (sta.size() > 0) {
                    sta.pop();
                }
                str = "";
            }
            if (str == ".") {
                str = "";
            }

            //assemble string
            while(sta.size() > 0) {
                str = sta.top() + "/" + str;
                sta.pop();
            }
            if (str.size() > 0 && str.back() == '/') {
                str.pop_back();
            }

            str = "/" + str;

            return str;
        }
    };