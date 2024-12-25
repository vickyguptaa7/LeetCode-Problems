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
    
    void helper(TreeNode*root,int row,vector<int>&res)
    {
        if(!root)
            return;
        
        if(res.size()==row)
            res.push_back(root->val);
        else 
            res[row]=max(res[row],root->val);
        
        helper(root->left,row+1,res);
        helper(root->right,row+1,res);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        helper(root,0,res);
        return res;
    }
};