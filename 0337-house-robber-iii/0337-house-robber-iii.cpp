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
    
    int helper(TreeNode*root,bool isRobPrev,map<pair<TreeNode*,int>,int>&dp)
    {
        if(!root)
            return 0;
        if(dp.count({root,isRobPrev}))
            return dp[{root,isRobPrev}];
        int notRobbingCurr=0,robbingCurr=0;
        notRobbingCurr+=helper(root->left,false,dp);
        notRobbingCurr+=helper(root->right,false,dp);
        
        if(!isRobPrev)
        {
            robbingCurr+=helper(root->left,true,dp);
            robbingCurr+=helper(root->right,true,dp);
            robbingCurr+=root->val;
        }
        return dp[{root,isRobPrev}]=max(notRobbingCurr,robbingCurr);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,int>,int>dp;
        return helper(root,false,dp);
    }
};