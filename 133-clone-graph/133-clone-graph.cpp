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
    void DFS_Clone(Node*newnode,Node*node,vector<Node*>&isVisited)
    {
        isVisited[node->val]=newnode;
        for(auto x:node->neighbors)
        {
            if(isVisited[x->val]==nullptr)
            {
                Node *clone=new Node(x->val);
                DFS_Clone(clone,x,isVisited);
            }
            (newnode->neighbors).push_back(isVisited[x->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        vector<Node*>isVisited(101,nullptr);
        Node*newnode=new Node(node->val);
        DFS_Clone(newnode,node,isVisited);
        return newnode;
    }
};