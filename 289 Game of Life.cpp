class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.at(0).size();
        //
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board.at(i).at(j) *= 10;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 9) {
                    if(i>0) board[i-1][j]++; // left
                    if(i<m-1) board[i+1][j]++; // right
                    if(j>0) board[i][j-1]++; // up
                    if(j<n-1) board[i][j+1]++; // down
                    if(i>0 && j>0) board[i-1][j-1]++; // north-west
                    if(i>0 && j<n-1) board[i-1][j+1]++; // north-east
                    if(i<m-1 && j>0) board[i+1][j-1]++; // south-west
                    if(i<m-1 && j<n-1) board[i+1][j+1]++; // south-east
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 9) { // cell is alive
                    if (board[i][j] >= 12 && board[i][j] <= 13) { //b/c we added 10 to alive cells earlier
                        board[i][j] = 1;
                    } else {
                        board[i][j] = 0;
                    }
                }
                else { //cell is dead
                    if (board[i][j] == 3) {
                        board[i][j] = 1;
                    }
                    else {
                        board[i][j] = 0;
                    }
                }
            }
        }

    }
};