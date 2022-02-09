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
    void helper(TreeNode* root, int targetSum,vector<int>ans,vector<vector<int>>&res)
    {
        if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            ans.push_back(root->val);
            if(targetSum==root->val)
            {
                res.push_back(ans);
            }
            return;
        }
        ans.push_back(root->val);
        helper(root->left,targetSum-root->val,ans,res);
        helper(root->right,targetSum-root->val,ans,res);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>res;
        vector<int>ans;
        helper(root,targetSum,ans,res);
        return res;
    }
};