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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>tree;
        unordered_map<int,int>parent;
        for(auto desc:descriptions)
        {
            if(!tree.count(desc[0]))
            {
                TreeNode*node=new TreeNode(desc[0]);
                tree[desc[0]]=node;
            }
            TreeNode*node=tree[desc[0]];
            TreeNode*child=nullptr;
            if(tree.count(desc[1]))
            {
                child=tree[desc[1]];
            }
            else
            {
                child=new TreeNode(desc[1]);
                tree[desc[1]]=child;
            }
            if(desc[2]==1)
            {
                node->left=child;
            }
            else
            {
                node->right=child;
            }
            parent[child->val]=node->val;
        }
        int par=descriptions[0][0];
        while(parent.count(par))
        {
            par=parent[par];
        }
        return tree[par];
    }
};