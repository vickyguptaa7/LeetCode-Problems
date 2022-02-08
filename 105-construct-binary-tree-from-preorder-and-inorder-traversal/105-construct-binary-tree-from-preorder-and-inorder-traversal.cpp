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
    TreeNode*helper(int &ps,int pe,int is,int ie,vector<int>&preorder,vector<int>&inorder)
    {
        if(ps>pe||is>ie)return nullptr;
        TreeNode*root=new TreeNode(preorder[ps++]);
        int index=is;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==preorder[ps-1])
            {
                index=i;
                break;
            }
        }
        root->left=helper(ps,pe,is,index-1,preorder,inorder);
        root->right=helper(ps,pe,index+1,ie,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int arrayLen=preorder.size()-1;
        int ps=0;
        return helper(ps,arrayLen,0,arrayLen,preorder,inorder);
    }
};