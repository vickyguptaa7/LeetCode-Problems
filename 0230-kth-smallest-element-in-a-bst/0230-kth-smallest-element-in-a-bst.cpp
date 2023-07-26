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
    
    bool helper(TreeNode*root,int &k,int &target)
    {
        if(!root)
            return false;
        if(helper(root->left,k,target))
            return true;
        k--;
        if(k==0)
        {
            target=root->val;
            return true;
        }
        if(helper(root->right,k,target))
            return true;
        return false;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int target=-1;
        helper(root,k,target);
        return target;
    }
};