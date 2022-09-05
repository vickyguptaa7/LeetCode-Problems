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
        if(!root)  return result;
        queue<Node*>que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            vector<int>row;
            while(size--)
            {
                Node*curr=que.front();
                que.pop();
                row.push_back(curr->val);
                for(auto x:curr->children)
                {
                    que.push(x);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};