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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q,int Max,int Min)
    {
        if(!root||p->val<Min||q->val<Min||p->val>Max||q->val>Max)return nullptr;
        
        TreeNode*left=helper(root->left,p,q,root->val,Min);
        if(left)return left;
        TreeNode*right=helper(root->right,p,q,Max,root->val);
        if(right)return right;
        
        if(p->val>Min&&q->val>Min&&p->val<Max&&q->val<Max)return root;
        
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q,1e9+5,-1e9-5);
    }
};