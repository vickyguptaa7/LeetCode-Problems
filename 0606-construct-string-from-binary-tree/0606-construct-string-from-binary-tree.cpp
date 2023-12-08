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
    
    void helper(TreeNode*root,string&res)
    {
        if(!root)
            return;
        res+=to_string(root->val);
        if(!root->left&&!root->right)
            return;
        res+="(";
        helper(root->left,res);
        res+=")";
        if(!root->right)return;
        res+="(";
        helper(root->right,res);
        res+=")";
    }
    
    string tree2str(TreeNode* root) {
        string res="";
        helper(root,res);
        return res;
    }
};