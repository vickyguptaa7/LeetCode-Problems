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
    int helper(TreeNode*root,int& res)
    {
        if(!root)
            return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        res=max(res,left+right+1);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res-1;
    }
};