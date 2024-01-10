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
    
    bool rootToNodePath(TreeNode*root,int node,vector<TreeNode*>&path)
    {
        if(!root)
            return false;
        if(root->val==node)
        {
            path.push_back(root);
            return true;
        }
        if(rootToNodePath(root->left,node,path))
        {
            path.push_back(root);
            return true;
        }
        if(rootToNodePath(root->right,node,path))
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    
    int helper(TreeNode*root,TreeNode*block)
    {
        if(!root||root==block)
            return 0;
        return 1+max(helper(root->left,block),helper(root->right,block));
    }
    
    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*>path;
        rootToNodePath(root,start,path);
        int mxtime=0;
        for(int i=0;i<path.size();i++)
        {
            mxtime=max(i+helper(path[i],i==0?nullptr:path[i-1])-1,mxtime);
        }
        return mxtime;
        
    }
};