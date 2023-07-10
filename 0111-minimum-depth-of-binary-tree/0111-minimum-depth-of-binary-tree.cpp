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
        if(!root)
            return 1e9;
        if(!root->left&&!root->right)
            return 1;
        return min(helper(root->left),helper(root->right))+1;
    }
    
    int minDepth(TreeNode* root) {
        int result=helper(root);
        return result!=1e9?result:0;
    }
};