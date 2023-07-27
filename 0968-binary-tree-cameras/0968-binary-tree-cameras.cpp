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
    
    int helper(TreeNode*root,int &minCamera)
    {
        if(!root)
            return 1;
        
        int left=helper(root->left,minCamera);
        int right=helper(root->right,minCamera);
        
        if(left==0||right==0)
        {
            minCamera++;
            return 2;
        }
        
        if(left==2||right==2)
            return 1;
        
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int minCamera=0;
        if(helper(root,minCamera)==0)minCamera++;
        return minCamera;
    }
};