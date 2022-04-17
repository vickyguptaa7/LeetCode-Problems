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
    
    void helper(TreeNode*root,TreeNode*&prev,TreeNode*&nroot)
    {
        if(!root)return;
        helper(root->left,prev,nroot);
        if(!nroot)nroot=root;

        if(prev==nullptr)prev=root;
        else
        {
            prev->left=nullptr;
            prev->right=root;
            prev=root;
        }
        helper(root->right,prev,nroot);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode*prev=nullptr,*nroot=nullptr;
        helper(root,prev,nroot);
        prev->left=nullptr;
        prev->right=nullptr;
        return nroot;
    }
};