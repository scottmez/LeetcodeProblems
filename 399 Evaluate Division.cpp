class Solution {
    unordered_map<string, vector<pair<string, double>>> adjList;
    unordered_map<string, bool> visited;
    double queryAns;
public:
    
    bool dfs(string startNode, string endNode, double runningProduct){

        //if the any of the nodes in the query are not in the graph, return false
        if(adjList.find(startNode) == adjList.end() || adjList.find (endNode) == adjList.end()) { 
            return false;
        }
        
        //if we reach the end node, and the end node is in the nodes list we have found a path
        if(startNode == endNode && adjList.find(startNode)!=adjList.end()) {
            queryAns = runningProduct;
            return true;
            
        }
        
        bool tempAns = false;
        visited[startNode] = true;
        
        for(int i = 0; i < adjList[startNode].size(); i++){
            //iterate through the adjacency list of the start node
            //if the adjacent node is not visited, we can visit it
            if(!visited[adjList[startNode][i].first]){ 
                //try dfs starting at the adjacent node
                //if we find a path to the end node, we can break out of the loop
                tempAns = dfs(adjList[startNode][i].first, endNode, runningProduct*adjList[startNode][i].second);
                if(tempAns){
                    break;
                }
            }
        }
        
        visited[startNode] = false;
        
        return tempAns;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        
        for(int i = 0; i < n ; i++){
            
            //map first letter in equation to the second letter and its value in the equation
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            //map second letter in equation to the first letter and its value in the equation
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]});

            //initialize the visited map to false for all nodes in the graph
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;

        }
        
        for(int i = 0; i < m ; i++){
            //loop through the queries
            queryAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);            
            if(pathFound) ans[i] = queryAns;
            else ans[i] = -1;
            
        }
        
        return ans;
        
    }
};