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
    
    
    bool isValidBST(TreeNode* root,long long mn=-1e12,long long mx=1e12) {
        if(!root)
            return 1;
        
        if(root->val<=mn||root->val>=mx)
            return false;
        
        if(!isValidBST(root->left,mn,root->val))
            return false;
        
        if(!isValidBST(root->right,root->val,mx))
            return false;
        
        return true;
        
    }
};