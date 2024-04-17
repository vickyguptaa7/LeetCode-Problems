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
    
    void helper(TreeNode*root,string curr,string &res)
    {
        if(!root)
        {
            return;
        }
        if(!root->left&&!root->right)
        {
            if(res.empty())
                res=char(root->val+'a')+curr;
            else
                res=min(res,char(root->val+'a')+curr);
            return;
        }
        helper(root->left,char('a'+root->val)+curr,res);
        helper(root->right,char('a'+root->val)+curr,res);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string res;
        helper(root,"",res);
        return res;
    }
};