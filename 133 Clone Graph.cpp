/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if (!node) {
                return nullptr;
            }
            
            queue<Node*> toVisit;
            unordered_map<Node*, Node*> oldToNew;
            Node* newNode = new Node(); //always newest node created
            Node* head = newNode; // first node created, will be returned
            Node* cur = newNode; // current node being constructed (attaching neighbors to)

            newNode->val = node->val;
            oldToNew.insert({node,newNode});
            cout << node->val << endl;
            for (Node* neighbor: node->neighbors) {
                //create new node and assign its value
                newNode = new Node(neighbor->val);
                cout << neighbor->val << endl;
                //add neighbors to cur's neighbor list
                cur->neighbors.push_back(newNode);
                //update state
                toVisit.push(neighbor);
                oldToNew.insert({neighbor,newNode});
            }

            while (!toVisit.empty()) {
                node = toVisit.front();
                toVisit.pop();
                cur = oldToNew.at(node);
                for (Node* neighbor: node->neighbors) {
                    if(oldToNew.find(neighbor) == oldToNew.end())  { //if not visited
                        newNode = new Node(neighbor->val);
                        cout << neighbor->val << endl;
                        toVisit.push(neighbor);
                        oldToNew.insert({neighbor,newNode});
                    }
                    newNode = oldToNew.at(neighbor);
                    cur->neighbors.push_back(newNode);
                }
            }

            return head;
        }
    };