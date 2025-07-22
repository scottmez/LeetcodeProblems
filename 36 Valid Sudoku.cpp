class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        rows
        cols
        boxes
        
        */
        vector<set<char> > rows = {{},{},{},{},{},{},{},{},{},{}}; 
        vector<set<char> > cols = {{},{},{},{},{},{},{},{},{},{}};
        vector<set<char> > boxes = {{},{},{},{},{},{},{},{},{},{}};
        char t = ' ';

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                t = board[i][j];
                if (t - '0' >= 1 && t - '0' <= 9) {
                    int temp = 3*(j/3)+ (i/3);
                    //cout << temp << endl;
                    auto itrR = rows.at(i).insert(t);
                    auto itrC = cols.at(j).insert(t);
                    auto itrB = boxes.at(temp).insert(t);
                    if(!itrR.second || !itrC.second || !itrB.second) { //the itr_.second will be true if it was allowed to insert
                        //if any are false, return false
                        return false;
                    }
                }
            }  
        }

        return true;
    }
};