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
    
    void dfs(TreeNode*root,vector<int>&v)
    {
        if(!root)
            return;
        if(!root->left&&!root->right)
        {
            v.push_back(root->val);
            return;
        }
        dfs(root->left,v);
        dfs(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>l1,l2;
        dfs(root1,l1);
        dfs(root2,l2);
        if(l1==l2)
        {
            return true;
        }
        return false;
    }
};