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
        
        vector<int>result;
        rootToNode(root,target,k,result);
        return result;
    }
    
    int rootToNode(TreeNode*root,TreeNode*target,int k,vector<int>&result)
    {
        if(!root)return -1;
        if(root==target)
        {
            k_level_down(root,k,nullptr,result);
            return 1;
        }
        int leftDepth=rootToNode(root->left,target,k,result);
        if(leftDepth!=-1)
        {
            k_level_down(root,k-leftDepth,root->left,result);
            return 1+leftDepth;
        }
        int rightDepth=rootToNode(root->right,target,k,result);
        if(rightDepth!=-1)
        {
            k_level_down(root,k-rightDepth,root->right,result);
            return 1+rightDepth;
        }
        return -1;
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
};

/*
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
*/