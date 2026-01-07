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

    int dfsSum(TreeNode*root)
    {
        if(!root)
            return 0;
        
        return dfsSum(root->left)+dfsSum(root->right)+root->val;
    }

    int dfsMaxProduct(TreeNode*root,long long& max_product,int total_sum)
    {
        if(!root)
            return 0;
        int sum = root->val + dfsMaxProduct(root->left,max_product,total_sum)+dfsMaxProduct(root->right,max_product,total_sum);
        max_product=max(max_product,sum*1ll*(total_sum-sum));
        return sum;
    }

    int maxProduct(TreeNode* root) {
        int total_sum = dfsSum(root);
        long long max_product=1;
        dfsMaxProduct(root,max_product,total_sum);
        int mod=1e9+7;
        return (max_product)%mod;
    }
};