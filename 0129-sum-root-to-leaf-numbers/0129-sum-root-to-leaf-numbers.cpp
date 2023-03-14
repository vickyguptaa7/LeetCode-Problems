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
    int sumNumbers(TreeNode* root,string num="0") {
        if(!root)
            return 0;
        if(!root->left&&!root->right)
        {
            return stoi(num+to_string(root->val));
        }
        return sumNumbers(root->left,num+to_string(root->val))+
               sumNumbers(root->right,num+to_string(root->val));
    }
};