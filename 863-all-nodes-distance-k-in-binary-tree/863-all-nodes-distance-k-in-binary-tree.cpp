/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<TreeNode*>path;
        rootToNodePath(root,path,target);
        vector<int>result;
        for(int i=0;i<path.size();i++)
        {
            k_level_down(path[i],k-i,(i==0)?nullptr:path[i-1],result);
        }
        return result;
    }
    
    void k_level_down(TreeNode*root,int lvl,TreeNode*block,vector<int>&result)
    {
        if(!root||root==block)return;
        if(lvl==0)
        {
            result.push_back(root->val);
        }
        k_level_down(root->left,lvl-1,block,result);
        k_level_down(root->right,lvl-1,block,result);
    }
    
    bool rootToNodePath(TreeNode*root,vector<TreeNode*>&path,TreeNode* target)
    {
        if(!root)return false;
        if(root==target)
        {
            path.push_back(root);
            return true;
        }
        if(rootToNodePath(root->left,path,target))
        {
            path.push_back(root);
            return true;
        }
        if(rootToNodePath(root->right,path,target))
        {
            path.push_back(root);
            return true;
        }
        return false;
        
    }
};