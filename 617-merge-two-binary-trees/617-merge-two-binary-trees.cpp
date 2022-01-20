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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr&&root2==nullptr)
        {
            return nullptr;
        }
        TreeNode*newnode=new TreeNode;
        if(root1==nullptr)
        {
            newnode->val=(root2->val);
            newnode->left=mergeTrees(root1,root2->left);
            newnode->right=mergeTrees(root1,root2->right);
        }
        else if(root2==nullptr)
        {
            newnode->val=(root1->val);
            newnode->left=mergeTrees(root1->left,root2);
            newnode->right=mergeTrees(root1->right,root2);
        }
        else
        {
            newnode->val=(root2->val+root1->val);
            newnode->left=mergeTrees(root1->left,root2->left);
            newnode->right=mergeTrees(root1->right,root2->right);
        }
        return newnode;
    }
};