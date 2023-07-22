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
        if(!root1&&!root2)
            return nullptr;
        int sum=0;
        if(root1)
            sum+=root1->val;
        if(root2)
            sum+=root2->val;
        
        TreeNode*node=new TreeNode(sum);
        
        node->left=mergeTrees(root1?root1->left:root1,root2?root2->left:root2);
        node->right=mergeTrees(root1?root1->right:root1,root2?root2->right:root2);
        
        return node;
    }
};