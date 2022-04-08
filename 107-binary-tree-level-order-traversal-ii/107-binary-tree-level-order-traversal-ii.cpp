/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>list;
        if(root==nullptr)return list;
        stack<vector<int>>st;
        
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            vector<int>lvl;
            while(size--)
            {
                TreeNode*curr=que.front();
                lvl.push_back(curr->val);
                if(curr->left)que.push(curr->left);
                if(curr->right)que.push(curr->right);
                que.pop();
            }
            st.push(lvl);
        }
        while(!st.empty())
        {
            list.push_back(st.top());
            st.pop();
        }
        return list;
    }
};