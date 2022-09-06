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
    int helper(TreeNode*root)
    {
        if(!root)return 0;
        
        int left=helper(root->left);
        int right=helper(root->right);
        
        if(left==0)root->left=nullptr;
        if(right==0)root->right=nullptr;
        
        return left+right+(root->val==1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return root;
        if(root->val==0&&!root->left&&!root->right)return nullptr;
        
        helper(root);
        if(root->val==0&&!root->left&&!root->right)return nullptr;
        return root;
    }
};