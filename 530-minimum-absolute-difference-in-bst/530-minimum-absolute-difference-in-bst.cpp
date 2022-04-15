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
    
    void helper(TreeNode*root,int &absDiff,TreeNode*&prev)
    {
        if(!root)return;
        helper(root->left,absDiff,prev);
        int preVal=(prev==nullptr)?1e9:prev->val;
        absDiff=min(absDiff,abs(root->val-preVal));
        prev=root;
        helper(root->right,absDiff,prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
        TreeNode*prev=nullptr;
        int absDiff=1e9;
        helper(root,absDiff,prev);
        return absDiff;
    }
};