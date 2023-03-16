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
    
    TreeNode* buildTreeHelper(int &rootIndx,int strt,int end,vector<int>&inorder,vector<int>&postorder)
    {
        if(strt>end)
            return nullptr;
        if(strt==end)
        {
            return new TreeNode(postorder[rootIndx--]);
        }
        
        int indx=0;
        for(int i=strt;i<=end;i++)
        {
            if(inorder[i]==postorder[rootIndx])
            {
                indx=i;
                break;
            }
        }
        TreeNode*root=new TreeNode(postorder[rootIndx--]);
        root->right=buildTreeHelper(rootIndx,indx+1,end,inorder,postorder);
        root->left=buildTreeHelper(rootIndx,strt,indx-1,inorder,postorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int rootIndx=n-1;
        return buildTreeHelper(rootIndx,0,n-1,inorder,postorder);
    }
};