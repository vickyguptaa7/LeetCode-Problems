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
    void helper(TreeNode*root,int tarSum,int currSum,vector<int>&node,vector<vector<int>>&result)
    {
        if(!root)return;
        if(!root->left&&!root->right)
        {
            if(currSum+root->val==tarSum)
            {
                node.push_back(root->val);
                result.push_back(node);
                node.pop_back();
            }
            return;
        }
        node.push_back(root->val);
        helper(root->left,tarSum,currSum+root->val,node,result);
        helper(root->right,tarSum,currSum+root->val,node,result);
        node.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int>nodes;
        int currSum=0;
        helper(root,targetSum,currSum,nodes,result);
        return result;
    }
};