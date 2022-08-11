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
    bool helper(TreeNode*root,long long max,long long min)
    {
        if(!root)return true;
        if(root->val<=min||root->val>=max)return false;
        
        if(!helper(root->left,root->val,min))return false;
        if(!helper(root->right,max,root->val))return false;
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,1e12,-1e12);
    }
};