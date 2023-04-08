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
    unordered_map<int,Node*>visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node*newNode=new Node(node->val);
        visited[newNode->val]=newNode;
        for(auto child:node->neighbors)
        {
            if(visited.count(child->val))
                newNode->neighbors.push_back(visited[child->val]);
            else
                newNode->neighbors.push_back(cloneGraph(child));
        }
        return newNode;
    }
};