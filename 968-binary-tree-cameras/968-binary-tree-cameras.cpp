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
    
    int helper(TreeNode*root,int &ans)
    {
        if(!root)return 1;
        
        int leftCh=helper(root->left,ans);
        int rightCh=helper(root->right,ans);
        
        if(leftCh==-1||rightCh==-1)
        {
            ans++;
            return 2;
        }
        if(leftCh==1&&rightCh==1)
        {
            return -1;
        }
        if((leftCh==1&&rightCh==2)||(leftCh==2&&rightCh==1))
        {
            return 1;
        }
        if(leftCh==2&&rightCh==2)return 1;
        
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int ans=0;
        int choice=helper(root,ans);
        if(choice==-1)ans++;
        return ans;
    }
};