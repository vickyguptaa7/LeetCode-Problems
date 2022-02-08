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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==nullptr)return result;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        bool isSt=1;
        while(!st1.empty()||!st2.empty())
        {
            int size=max(st2.size(),st1.size());
            vector<int>row;
            while(size--)
            {
                if(isSt)
                {
                    TreeNode*curr=st1.top(); 
                    row.push_back(curr->val);
                    st1.pop();
                    if(curr->left)
                    {
                        st2.push(curr->left);
                    }
                    if(curr->right)
                    {
                        st2.push(curr->right);
                    }
                    
                }
                else
                {
                    TreeNode*curr=st2.top(); 
                    row.push_back(curr->val);
                    st2.pop();
                    if(curr->right)
                    {
                        st1.push(curr->right);
                    }
                    if(curr->left)
                    {
                        st1.push(curr->left);
                    }
                    
                }
            }
            isSt=!isSt;
            result.push_back(row);
        }
        return result;
    }
};