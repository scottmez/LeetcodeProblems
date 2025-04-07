class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if (board.empty() || board[0].empty() || board.size() < 3 || board[0].size() < 3) {
                return; // return if the board is empty
            }
            int width = board.size();
            int height = board[0].size();
            vector<vector<bool>> visited(width, vector<bool>(height, false)); // to keep track of visited cells
            //we want to 'capture' all the regions of 'O's that are surrounded by 'X's, which means we will start from the boundary

            for (int i = 0; i < width; i++) { //top
                for (int j = 0; j < height; j+=height-1) { //top/bottom
                    // start from the boundary cells
                    if ((i == 0 || i == width - 1 || j == 0 || j == height - 1) && board[i][j] == 'O' && !visited[i][j]) {
                        // perform DFS or BFS to mark all connected 'O's
                        dfs(board, visited, i, j);
                    }
                }
            }

            //now we check left/right
            for (int i = 0; i < width; i+=width-1) { //left/right
                for (int j = 0; j < height; j++) {
                    // start from the boundary cells
                    if ((i == 0 || i == width - 1 || j == 0 || j == height - 1) && board[i][j] == 'O' && !visited[i][j]) {
                        // perform DFS or BFS to mark all connected 'O's
                        dfs(board, visited, i, j);
                    }
                }
            }

            //now we have visited all the 'O's that are connected to the boundary
            //we can now flip all the remaining 'O's to 'X's
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    if (board[i][j] == 'O' && !visited[i][j]) {
                        board[i][j] = 'X'; // flip to 'X'
                    }
                }
            }
        }

        void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
            // base case for out of bounds or water cell
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || visited[i][j]) {
                return;
            }
            // mark the cell as visited
            visited[i][j] = true;

            // explore all 4 directions (up, down, left, right)
            dfs(board, visited, i - 1, j); // up
            dfs(board, visited, i + 1, j); // down
            dfs(board, visited, i, j - 1); // left
            dfs(board, visited, i, j + 1); // right
        }
    };