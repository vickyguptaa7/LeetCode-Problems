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
    
    void helper(TreeNode*root,TreeNode*&prev)
    {
        if(!root)
            return;
        
        TreeNode*rightPtr=root->right;
        if(prev!=nullptr)
        {
            prev->right=root;
            prev->left=nullptr;
        }
        prev=root;
        helper(root->left,prev);
        helper(rightPtr,prev);
    }
    
    void flatten(TreeNode* root) {
        TreeNode*head=root,*prev=nullptr;
        helper(root,prev);
    }
};