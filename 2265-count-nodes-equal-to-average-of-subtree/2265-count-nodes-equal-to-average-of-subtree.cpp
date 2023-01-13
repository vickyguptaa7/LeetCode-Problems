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
    pair<int,int> helper(TreeNode*root,int &result)
    {
        if(!root)
            return {0,0};
        auto left=helper(root->left,result);
        auto right=helper(root->right,result);
        if((left.first+right.first+root->val)/(left.second+right.second+1)
           ==root->val)
            result++;
        return {left.first+right.first+root->val,left.second+right.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        helper(root,result);
        return result;
    }
};