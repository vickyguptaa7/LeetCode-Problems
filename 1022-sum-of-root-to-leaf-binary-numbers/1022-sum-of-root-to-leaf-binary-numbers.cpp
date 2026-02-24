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
    int helper(TreeNode*root,int num)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left&&!root->right)
        {
            return num*2+root->val;
        }
        int left = helper(root->left,2*num+root->val);
        int right = helper(root->right,2*num+root->val);

        return left + right;
    }

    int sumRootToLeaf(TreeNode* root) {
        return helper(root,0);
    }
};