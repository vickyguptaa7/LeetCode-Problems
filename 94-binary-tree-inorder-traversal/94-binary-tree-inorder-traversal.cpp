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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>stck;
        vector<int>res;
        while(root || !stck.empty())
        {
            while(root)
            {
                stck.push(root);
                root=root->left;
            }
            root=stck.top();
            res.push_back(root->val);
            stck.pop();
            root=root->right;
        }
        return res;
    }
};