class Solution {
    private:
        bool dfs(int i, vector<vector<int>>& adj, unordered_set<int>& set, vector<bool>& visited) {
            //add node i to the set of traversed nodes 
            //when dfs is called in the if statement below i is still in the set
            set.insert(i);
            visited[i] = true;
    
            for (int num : adj[i]) {
                if (!visited[num]) {
                    if (!dfs(num, adj, set, visited))
                        return false;
                } else if (set.count(num)) {
                    return false;
                }
            }
    
            set.erase(i);
            return true;
        }
    
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
            for (auto& edge : prerequisites) {
                //access the required list of courses for course 1 and add course 0 to it
                //(course 0 is a prerequisite for course 1)
                adj[edge[1]].push_back(edge[0]);
            }
    
            vector<bool> visited(numCourses, false);
            for (int i = 0; i < numCourses; ++i) {
                if (!visited[i]) {
                    unordered_set<int> set;
                    if (!dfs(i, adj, set, visited))
                        return false;
                }
            }
    
            return true;
        }
    };