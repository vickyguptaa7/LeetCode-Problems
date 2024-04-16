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
    
    TreeNode* helper(TreeNode*root,int val,int depth)
    {
        if(!root)
            return nullptr;
        if(depth==2)
        {
            TreeNode*curr1=new TreeNode(val);
            curr1->left=root->left;
            root->left=curr1;
            TreeNode*curr2=new TreeNode(val);
            curr2->right=root->right;
            root->right=curr2;
            return root;
        }
        root->left=helper(root->left,val,depth-1);
        root->right=helper(root->right,val,depth-1);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode*curr=new TreeNode(val);
            curr->left=root;
            return curr;
        }
        return helper(root,val,depth);
    }
};