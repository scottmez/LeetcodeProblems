class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int islands = 0;
            if (grid.empty()) {
                return islands; // return 0 if the grid is empty
            }
            int rows = grid.size();
            int cols = grid[0].size();
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // to keep track of visited cells
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == '1' && !visited[i][j]) { // found an unvisited land cell
                        islands++; // increment the island count
                        // perform DFS or BFS to mark all connected land cells
                        dfs(grid, visited, i, j);
                    }
                }
            }
            return islands; // return the total number of islands found
        }

        void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
            // base case for out of bounds or water cell
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) {
                return;
            }
            // mark the cell as visited
            visited[i][j] = true;

            // explore all 4 directions (up, down, left, right)
            dfs(grid, visited, i - 1, j); // up
            dfs(grid, visited, i + 1, j); // down
            dfs(grid, visited, i, j - 1); // left
            dfs(grid, visited, i, j + 1); // right
        }
    };