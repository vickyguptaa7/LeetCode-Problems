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
    
    bool rootToNodePath(TreeNode*root,int target,vector<pair<int,char>>&path)
    {
        if(!root)return false;
        
        if(target==root->val)
        {
            path.push_back({root->val,0});
            return true;            
        }
        
        if(rootToNodePath(root->left,target,path)){
            path.push_back({root->val,'L'});
            return true;
        }
        if(rootToNodePath(root->right,target,path)){
            path.push_back({root->val,'R'});
            return true;
        }
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<pair<int,char>>path1,path2;
        rootToNodePath(root,startValue,path1);
        rootToNodePath(root,destValue,path2);
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        int commonIndx=-1;
        for(int i=0;i<min(path2.size(),path1.size());i++)
        {
            if(path1[i].first!=path2[i].first)
            {
                break;
            }
            commonIndx=i;
        }
        
        string res;
        for(int i=commonIndx+1;i<path1.size();i++)
        {
            res+="U";
        }
        for(int i=commonIndx;i+1<path2.size();i++)
        {
            res+=path2[i].second;
        }
        return res;
    }
};