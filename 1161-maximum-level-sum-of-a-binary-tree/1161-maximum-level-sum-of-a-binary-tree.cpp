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

    void dfs(TreeNode*root, int lvl, vector<int>&sum)
    {
        if(!root)
            return;
        if(sum.size()==lvl)
            sum.push_back(root->val);
        else 
            sum[lvl]+=root->val;
        dfs(root->left,lvl+1,sum);
        dfs(root->right,lvl+1,sum);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int>sum;
        sum.push_back(INT_MIN);
        dfs(root,1,sum);
        return max_element(sum.begin(),sum.end())-sum.begin();
    }
};