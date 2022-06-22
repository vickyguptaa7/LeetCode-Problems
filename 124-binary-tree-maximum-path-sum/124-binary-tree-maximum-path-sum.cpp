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
    int maxPathSumHelper(TreeNode*root,int &ans)
    {
        if(!root)return 0;
        
        int leftSum=maxPathSumHelper(root->left,ans);
        int rightSum=maxPathSumHelper(root->right,ans);
    
        ans=max(ans,leftSum+rightSum+root->val);
        ans=max(ans,leftSum+root->val);
        ans=max(ans,rightSum+root->val);
        ans=max(ans,root->val);
        
        return max(0,max(leftSum,rightSum))+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
        maxPathSumHelper(root,ans);
        return ans;
    }
};