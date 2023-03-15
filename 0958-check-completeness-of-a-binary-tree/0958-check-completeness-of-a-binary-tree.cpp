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
    int countNode(TreeNode*root)
    {
        if(!root)return 0;
        return countNode(root->left)+1+countNode(root->right);
    }
    bool isCompleteTreeHelper(TreeNode*root,int indx,int number)
    {
        if(!root)
            return true;
        
        if(number<=indx)
            return false;
        
        if(!isCompleteTreeHelper(root->left,2*indx+1,number))return false;
        if(!isCompleteTreeHelper(root->right,2*indx+2,number))return false;
        
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return isCompleteTreeHelper(root,0,countNode(root));
    }
};