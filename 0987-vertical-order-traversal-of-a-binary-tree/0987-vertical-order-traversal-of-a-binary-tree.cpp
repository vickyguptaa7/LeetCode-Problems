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
    
    void helperDfs(TreeNode*root,int level,int position,map<int,map<int,vector<int>>>&traversalNodes)
    {
        if(!root)
        {
            return;
        }
        traversalNodes[position][level].push_back(root->val);
        helperDfs(root->left,level+1,position-1,traversalNodes);
        helperDfs(root->right,level+1,position+1,traversalNodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>nodes;
        map<int,map<int,vector<int>>>traversalNodes;
        helperDfs(root,0,0,traversalNodes);
        for(auto x:traversalNodes)
        {
            vector<int>temp;
            for(auto y:x.second)
            {
                sort(y.second.begin(),y.second.end());
                for(int i=0;i<y.second.size();i++)
                    temp.push_back(y.second[i]);
            }
            nodes.push_back(temp);
        }
        return nodes;
    }
};