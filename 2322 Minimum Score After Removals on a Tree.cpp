class Solution {
public:
    vector< vector<int> > adj_list; //adjacency list for storing the graph
    vector< unordered_set<int> > subtree_sets; 
    vector<int> subtree_xors;

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        //Build the Graph
        
        adj_list.resize(nums.size()); //resize to accomodate all vertices (each vertex has at least one edge in a connected tree)
        for (int i = 0; i < edges.size(); i++) {
            int first = edges.at(i).at(0);
            int second = edges.at(i).at(1);
            adj_list[first].push_back(second);
            adj_list[second].push_back(first);
        }

        //DFS Pre-computation
        subtree_sets.resize(nums.size());
        subtree_xors.resize(nums.size());

        dfs(0, -1, nums);

        //Simulate Cuts
        int total_xor = subtree_xors[0];
        int min_score = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int xor_i = subtree_xors[i];
                int xor_j = subtree_xors[j];
                int val1, val2, val3;

                if (subtree_sets[i].count(j)) { // j is in i's subtree
                    val1 = xor_j;
                    val2 = xor_i ^ xor_j;
                    val3 = total_xor ^ xor_i;
                }
                else if (subtree_sets[j].count(i)) { // i is in j's subtree
                    val1 = xor_i;
                    val2 = xor_j ^ xor_i;
                    val3 = total_xor ^ xor_j;
                }
                else {  //independent subtrees
                    val1 = xor_i;
                    val2 = xor_j;
                    val3 = total_xor ^ xor_i ^ xor_j;
                }

                int score = max({val1,val2,val3}) - min({val1,val2,val3});
                min_score = min(min_score,score);
            }
        }
        return min_score;
    }

    void dfs(int cur_node, int parent, vector<int>&nums) {
        subtree_xors.at(cur_node) = nums.at(cur_node);
        subtree_sets.at(cur_node).insert(cur_node);

        for (int neighbor : adj_list[cur_node]) {
            if(neighbor != parent) {
                dfs(neighbor, cur_node, nums);
                subtree_xors.at(cur_node) ^= subtree_xors.at(neighbor);
                subtree_sets.at(cur_node).insert(subtree_sets.at(neighbor).begin(), subtree_sets.at(neighbor).end()); 
            }
        }
    }
};