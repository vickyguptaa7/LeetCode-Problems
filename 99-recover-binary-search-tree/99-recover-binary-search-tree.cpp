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
    
    void helper(TreeNode*root,TreeNode* &prev,TreeNode* &left,TreeNode* &right)
    {
        if(!root)return;
        helper(root->left,prev,left,right);
        if(prev&&root->val<prev->val)
        {
            if(!left)
            {
                left=prev;
                right=root;
            }
            else 
            {
                right=root;
            }
        }
        prev=root;
        helper(root->right,prev,left,right);
    }
    
    void recoverTree(TreeNode* root) {
        if(!root)return;
        TreeNode*left=nullptr,*right=nullptr,*prev=nullptr;

        helper(root,prev,left,right);
        cout<<left->val<<" "<<right->val<<"\n";
                swap(left->val,right->val);
    }
};