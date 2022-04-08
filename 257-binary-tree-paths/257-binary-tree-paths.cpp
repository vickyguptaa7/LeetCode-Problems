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
    void helper(TreeNode*root,string ans,vector<string>&res)
    {
        if(!root)
        {
            return;
        }
        if(!root->left&&!root->right)
        {
            ans+=to_string(root->val)+"->";
            ans=ans.substr(0,ans.size()-2);
            res.push_back(ans);
            return ;
        }
        
        helper(root->left,ans+to_string(root->val)+"->",res);
        helper(root->right,ans+to_string(root->val)+"->",res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        helper(root,"",res);
        return res;
    }
};