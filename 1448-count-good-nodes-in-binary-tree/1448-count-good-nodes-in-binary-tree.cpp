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
    int helper(TreeNode*root,int maxVal)
    {
        if(!root)return 0;
        maxVal=max(maxVal,root->val);
        int left=helper(root->left,maxVal);
        int right=helper(root->right,maxVal);
        
        return left+right+(root->val>=maxVal);
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};