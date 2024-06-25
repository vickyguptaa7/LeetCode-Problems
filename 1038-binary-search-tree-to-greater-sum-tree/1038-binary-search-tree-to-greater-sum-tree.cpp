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
    
    int helper(TreeNode*root,int& sum)
    {
        if(!root)
            return 0;
        
        int rsum=helper(root->right,sum);
        sum+=root->val;
        int lsum=helper(root->left,sum);
        int oldVal=root->val;
        root->val=sum-lsum;
        return lsum+rsum+oldVal;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return root;
    }
};