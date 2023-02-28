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
    string dfs(TreeNode*root,vector<TreeNode*>&result,map<string,int>&mmp)
    {
        if(!root)
            return "@";
        string res="";
        res+=dfs(root->left,result,mmp);
        res+=",";
        res+=dfs(root->right,result,mmp);
        res+=","+to_string(root->val);
        mmp[res]++;
        if(mmp.count(res)&&mmp[res]==2)
        {
            result.push_back(root);
        }
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>result;
        map<string,int>mmp;
        dfs(root,result,mmp);
        return result;   
    }
};