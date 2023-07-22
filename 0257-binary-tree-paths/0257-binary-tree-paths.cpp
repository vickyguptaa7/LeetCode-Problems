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
    
    void helper(TreeNode*root,string currPath,vector<string>&paths)
    {
        if(!root)
            return;
        if(!root->left&&!root->right)
        {
            paths.push_back(currPath+to_string(root->val));
            return;
        }
        helper(root->left,currPath+to_string(root->val)+"->",paths);
        helper(root->right,currPath+to_string(root->val)+"->",paths);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        helper(root,"",paths);
        return paths;
    }
};