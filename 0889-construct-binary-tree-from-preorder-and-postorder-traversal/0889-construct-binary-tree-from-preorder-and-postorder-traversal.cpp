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
    
    TreeNode* helper(int &it1,int &it2,vector<int>&preorder,vector<int>&postorder)
    {
        TreeNode*curr=new TreeNode(preorder[it1++]);
        
        if(curr->val!=postorder[it2])
            curr->left=helper(it1,it2,preorder,postorder);
        if(curr->val!=postorder[it2])
            curr->right=helper(it1,it2,preorder,postorder);
        
        it2++;
        return curr;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int it1=0,it2=0;
        return helper(it1,it2,preorder,postorder);
    }
};