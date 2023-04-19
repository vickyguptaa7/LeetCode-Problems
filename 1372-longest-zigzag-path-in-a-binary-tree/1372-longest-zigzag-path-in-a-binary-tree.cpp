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
    
    void helper(TreeNode*root,int move,int len,int &ans)
    {
        if(!root)
            return;
        ans=max(ans,len);
        helper(root->left,1,(move==2||move==0)?len+1:1,ans);
        helper(root->right,2,(move==1||move==0)?len+1:1,ans);
    }
    
    int longestZigZag(TreeNode* root) {
        int ans=0;
        helper(root,0,0,ans);
        return ans;
    }
};