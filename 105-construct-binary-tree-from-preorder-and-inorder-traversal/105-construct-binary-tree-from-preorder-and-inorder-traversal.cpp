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
    
    TreeNode*helper(int &pindx,int strt,int end,vector<int>&preorder,vector<int>&inorder)
    {
        if(strt>end||pindx==preorder.size())
            return nullptr;
        int mid;
        for(int i=strt;i<=end;i++)
        {
            if(preorder[pindx]==inorder[i])
            {
                mid=i;
                break;
            }
        }
        pindx++;
        TreeNode*root=new TreeNode(inorder[mid]);
        root->left=helper(pindx,strt,mid-1,preorder,inorder);
        root->right=helper(pindx,mid+1,end,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pindx=0;
        int strt=0,end=inorder.size()-1;
        
        return helper(pindx,strt,end,preorder,inorder);
    }
};