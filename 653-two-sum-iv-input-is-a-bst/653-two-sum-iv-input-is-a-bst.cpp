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
    
    bool helper(TreeNode*root,int target)
    {
        if(!root)return false;
        if(root->val==target)return true;
        else if(root->val>target) return helper(root->left,target);
        return helper(root->right,target);
    }
    bool  inorder(TreeNode*root,TreeNode*head,int k)
    {
        if(!root)return false;
        if(k-2*root->val!=0&&helper(head,k-root->val))return true;
        
        return inorder(root->left,head,k)|inorder(root->right,head,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root->left&&!root->right)return false;
        return inorder(root,root,k);
    }
};