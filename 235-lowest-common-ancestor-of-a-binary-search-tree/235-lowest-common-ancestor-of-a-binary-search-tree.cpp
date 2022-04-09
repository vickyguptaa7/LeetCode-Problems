/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root==p||root==q)return root;
        
        TreeNode*left=lowestCommonAncestor(root->left,p,q);

        TreeNode*right=lowestCommonAncestor(root->right,p,q);

        
        if((left==p&&right==q)||(right==p&&left==q))return root;
        if(right)return right;
        if(left)return left;
        return nullptr;
    }
};