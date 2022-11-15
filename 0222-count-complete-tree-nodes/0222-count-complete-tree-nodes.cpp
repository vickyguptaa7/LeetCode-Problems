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
    int leftHeight(TreeNode*root)
    {
        int len=0;
        while(root!=nullptr)
        {
            len++;
            root=root->left;
        }
        return len;
    }
    int rightHeight(TreeNode*root)
    {
        int len=0;
        while(root!=nullptr)
        {
            len++;
            root=root->right;
        }
        return len;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh=leftHeight(root->left);
        int rh=rightHeight(root->right);
        if(lh==rh)
        {
            return (1<<(lh+1))-1;
        }
        else 
        {
            return countNodes(root->left)+1+countNodes(root->right);
        }
    }
};