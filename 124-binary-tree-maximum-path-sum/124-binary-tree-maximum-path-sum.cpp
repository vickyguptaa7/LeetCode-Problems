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
        
        int leftSum=max(maxPathSumHelper(root->left,ans),0);
        int rightSum=max(maxPathSumHelper(root->right,ans),0);
    
        ans=max(ans,leftSum+rightSum+root->val);
        
        return max(leftSum,rightSum)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
        maxPathSumHelper(root,ans);
        return ans;
    }
};