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
    
    void helper(TreeNode*root,vector<double>&res,vector<int>&nCount,int lvl)
    {
        if(!root)return;
        if(lvl==res.size())
        {
            res.push_back(root->val);
            nCount.push_back(1);
        }
        else
        {
            res[lvl]+=root->val;
            nCount[lvl]++;
        }
        helper(root->left,res,nCount,lvl+1);
        helper(root->right,res,nCount,lvl+1);
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        vector<int>nCount;
        helper(root,res,nCount,0);
        for(int i=0;i<nCount.size();i++)
        {
            res[i]/=nCount[i];
        }
        return res;
    }
};