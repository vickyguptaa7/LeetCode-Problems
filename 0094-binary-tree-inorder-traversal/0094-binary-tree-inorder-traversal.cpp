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
        if(!root)
            return {};
        stack<TreeNode*>recurStack;
        vector<int>result;
        while(!recurStack.empty()||root)
        {
            if(root->left)
            {
                recurStack.push(root);
                root=root->left;
                continue;
            }
            if(root->right)
            {
                result.push_back(root->val);
                root=root->right;
                continue;
            }
            result.push_back(root->val);
            while(!recurStack.empty()&&!recurStack.top()->right)
            {
                result.push_back(recurStack.top()->val); 
                recurStack.pop();
            }
            if(!recurStack.empty())
            {
                root=recurStack.top()->right;
                result.push_back(recurStack.top()->val);
                recurStack.pop();
            }
            else 
                root=nullptr;
        }
        return result;
    }
};