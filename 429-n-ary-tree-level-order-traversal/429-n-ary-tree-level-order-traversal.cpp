/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> result;
        if(!root)return result;
        queue<Node*>que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            vector<int>lvl;
            while(size--)
            {
                Node*parent=que.front();
                que.pop();
                lvl.push_back(parent->val);
                for(auto curr:parent->children)
                {
                    que.push(curr);
                }
            }
            result.push_back(lvl);
        }
        return result;
    }
};