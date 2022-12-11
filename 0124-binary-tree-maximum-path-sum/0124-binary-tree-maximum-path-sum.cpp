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
    int helper(TreeNode*root,int &maxSum)
    {
        if(!root)
        {
            return 0;
        }
        int leftSum=helper(root->left,maxSum);
        int rightSum=helper(root->right,maxSum);
        
        maxSum=max(maxSum,leftSum+rightSum+root->val);
        int mx=max(rightSum+root->val,leftSum+root->val);
        mx=max(mx,root->val);
        maxSum=max(maxSum,mx);
        return max(mx,0);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=-1e9;
        helper(root,maxSum);
        return maxSum;
    }
};