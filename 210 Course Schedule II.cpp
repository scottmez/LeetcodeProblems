class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            if (prerequisites.empty()) {
                vector<int> v(numCourses); 
                for (int i = 0; i < numCourses; i++) {
                    v[i] = i;
                }
                return v; //returns an array of 0 to numCourses-1
            }
            unordered_map<int, vector<int>> courseToReq;
            //first populate the directed graph 
            //in this problem we use a map to represent it
            for (int i = 0; i < prerequisites.size(); i++) {
                //the second element is a prerequisite for the first element
                //therefore we append the first element to the list of prerequisites for the second element
                courseToReq[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            //now we need to find the indegree of each node
            //we can do this by iterating through the map and counting the number of times each node appears in the list
            vector<int> indegree(numCourses, 0); //initialize indegree to 0 for all nodes
            for (auto& course : courseToReq) {
                for (int i = 0; i < course.second.size(); i++) {
                    indegree[course.second[i]]++;
                }
            }
            //now we need to find the nodes with indegree 0
            //we can do this by iterating through the indegree vector and adding the nodes with indegree 0 to a queue
            queue<int> q;
            for (int i = 0; i < indegree.size(); i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            //now we need to perform a topological sort on the graph
            vector<int> result;
            while (!q.empty()) {
                int course = q.front();
                q.pop();
                result.push_back(course);
                //now we need to iterate through the list of prerequisites for this course
                //and decrement the indegree of each prerequisite by 1
                for (int i = 0; i < courseToReq[course].size(); i++) {
                    indegree[courseToReq[course][i]]--;
                    if (indegree[courseToReq[course][i]] == 0) {
                        q.push(courseToReq[course][i]);
                    }
                }
            }

            return result.size() == numCourses ? result : vector<int>(); //if we have visited all nodes, return the result

        }
    };