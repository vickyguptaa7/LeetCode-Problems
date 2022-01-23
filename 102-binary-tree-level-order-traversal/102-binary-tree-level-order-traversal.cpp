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
        vector<vector<int>>list;
        if(root==nullptr)return list;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            vector<int>level;
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                level.push_back(curr->val);
                if(curr->left)
                que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            list.push_back(level);
        }
        return list;
    }
};