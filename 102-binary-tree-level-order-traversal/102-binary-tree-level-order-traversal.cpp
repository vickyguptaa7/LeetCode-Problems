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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            vector<int>row;
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                row.push_back(curr->val);
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            res.push_back(row);
        }
        return res;
    }
};