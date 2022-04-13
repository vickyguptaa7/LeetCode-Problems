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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return nullptr;
        if(depth==1)
        {
            TreeNode*newNode=new TreeNode(val);
            newNode->right=nullptr;
            newNode->left=root;
            return newNode;
        }
        if(depth==2)
        {
            TreeNode*newNodeLeft=new TreeNode(val);
            TreeNode*newNodeRight=new TreeNode(val);
            newNodeLeft->left=root->left;
            newNodeLeft->right=nullptr;
            newNodeRight->left=nullptr;
            newNodeRight->right=root->right;
            root->left=newNodeLeft;
            root->right=newNodeRight;
            return root;
        }
        addOneRow(root->left,val,depth-1);
        addOneRow(root->right,val,depth-1);
        return root;
    }
};