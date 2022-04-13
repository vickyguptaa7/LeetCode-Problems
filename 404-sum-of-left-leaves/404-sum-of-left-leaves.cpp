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
    int helper(TreeNode*root,bool isLeft)
    {
        if(!root)return 0;
        
        if(!root->left&&!root->right)
        {
            if(isLeft)return root->val;
            return 0;
        }
        int sum=0;
        sum+=helper(root->left,1);
        sum+=helper(root->right,0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        return helper(root,0);
    }
};