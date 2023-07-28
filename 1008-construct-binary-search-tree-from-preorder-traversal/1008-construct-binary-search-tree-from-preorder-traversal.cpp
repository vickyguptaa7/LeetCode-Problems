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
    
    TreeNode*helper(int& indx,vector<int>&preorder,int low,int high)
    {
        if(indx>=preorder.size())
            return nullptr;
        
        if(preorder[indx]<low||preorder[indx]>high)
            return nullptr;
        
        int val=preorder[indx++];
        TreeNode*curr=new TreeNode(val);
        
        curr->left=helper(indx,preorder,low,val);
        curr->right=helper(indx,preorder,val,high);
        
        return curr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int indx=0;
        return helper(indx,preorder,0,1001);
    }
};