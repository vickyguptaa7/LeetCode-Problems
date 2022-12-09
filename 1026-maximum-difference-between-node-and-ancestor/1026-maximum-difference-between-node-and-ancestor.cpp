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
    void helper(TreeNode*root,int _min,int _max,int &maxDiff)
    {
        maxDiff=max(_max-_min,maxDiff);
        if(!root)
            return;

        helper(root->left,min(root->val,_min),max(root->val,_max),maxDiff);
        helper(root->right,min(root->val,_min),max(root->val,_max),maxDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff=0;
        helper(root,root->val,root->val,maxDiff);
        return maxDiff;
    }
};