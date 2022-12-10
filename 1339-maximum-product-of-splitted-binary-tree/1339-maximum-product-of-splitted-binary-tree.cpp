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
    int SumTree(TreeNode*root)
    {
        if(!root)return 0;
        return SumTree(root->left)+SumTree(root->right)+root->val;
    }
    
    int helper(TreeNode*root,int totalSum,long long &result)
    {
        if(!root)
            return 0;
        
        int leftS=helper(root->left,totalSum,result);
        int rightS=helper(root->right,totalSum,result);
        result=max(result,max((totalSum-(long long)leftS)*leftS
                   ,(totalSum-(long long)rightS)*rightS));
        return leftS+root->val+rightS;
        
    }
    
    int maxProduct(TreeNode* root) {
        int treeSum=SumTree(root);
        long long result=0,mod=1e9+7;
        helper(root,treeSum,result);
        return result%mod;
    }
};