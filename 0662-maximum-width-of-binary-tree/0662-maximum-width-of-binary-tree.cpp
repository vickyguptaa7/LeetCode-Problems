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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>que;
        que.push({root,1});
        long long mxWidth=0;
        while(!que.empty())
        {
            int size=que.size();
            long long mn=1e9,mx=0;
            while(size--)
            {
                auto curr=que.front();
                que.pop();
                mn=min((long long)curr.second,mn);
                mx=max((long long)curr.second,mx);
                long long indx=curr.second-mn;
                if(curr.first->left)
                {
                    que.push({curr.first->left,indx*2});
                }
                if(curr.first->right)
                {
                    que.push({curr.first->right,indx*2+1});
                }
            }
            mxWidth=max(mxWidth,mx-mn+1);
        }
        return mxWidth;
    }
};