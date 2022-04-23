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
    void helper(TreeNode*root,int &result,int parent)
    {
        if(!root)return;
        if(root->val>=parent)
        {
            result++;
        }
        int Max=max(parent,root->val);
        helper(root->left,result,Max);
        helper(root->right,result,Max);
        
       
    }
    int goodNodes(TreeNode* root) {
        int result=0;
        helper(root,result,-1e5);
        return result;
    }
};