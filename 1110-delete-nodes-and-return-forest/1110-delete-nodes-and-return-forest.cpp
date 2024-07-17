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
    
    TreeNode* helper(TreeNode*root,set<int>&del,vector<TreeNode*>&res)
    {
        if(!root)return nullptr;
        root->left=helper(root->left,del,res);
        root->right=helper(root->right,del,res);
        if(del.count(root->val))
        {
            if(root->left)
            {
                res.push_back(root->left);
                root->left=nullptr;
            }
            if(root->right)
            {
                res.push_back(root->right);
                root->right=nullptr;
            }
            return nullptr;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>res;
        set<int>sto_delete(to_delete.begin(),to_delete.end());
        if(!sto_delete.count(root->val))
        {
            res.push_back(root);
        }
        
        helper(root,sto_delete,res);
        
        return res;
    }
};